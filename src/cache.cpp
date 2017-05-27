//
// Created by victor on 5/24/17.
//

#include <string.h>
#include <iostream>
#include <map>
#include <string>
#include "cache.h"
#include <iomanip>

cache::cache(){
    head_cache = NULL;
    tail_cache = NULL;
    cache_size = 0;
}

cache::~cache(){

}

cache* cache_instance = NULL;

cache* cache::Get_cache(){
    static pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
    if(cache_instance == NULL){
        pthread_mutex_lock(&mu);
        if(cache_instance == NULL)
            cache_instance = new cache();
        pthread_mutex_unlock(&mu);
    }
    return cache_instance;
}

int cache::cache_insert(char *code, char chunk_reference[], int code_length) {
    struct cache_list *add_member = new cache_list;
    std::string mid_code;
    struct Code_chunk *new_code_chunk = NULL;

    new_code_chunk = new Code_chunk;
    new_code_chunk -> next = NULL;
    memcpy(new_code_chunk -> chunk, chunk_reference, CHUNK_SIZE);
    chunk_container[mid_code] = new_code_chunk;

    code[code_length] = '\0';
    mid_code = code;

    if(head_cache == NULL){ //cache is empty


        add_member -> code = mid_code;
        add_member -> next = NULL;
        add_member -> prev = NULL;
        head_cache = add_member;
        cache_size++;
        return 1;
    }
    else{
        if(cache_size == 1){ //cache contained only one member

            add_member -> code = mid_code;
            add_member -> next = head_cache;
            head_cache -> next = add_member;
            add_member -> prev = head_cache;
            head_cache -> prev = add_member;
            tail_cache = head_cache;
            head_cache = add_member;
            cache_size++;
            return 1;
        }
        else if( cache_size == MAX_CACHE_SIZE) {

            add_member -> code = mid_code;
            add_member -> next = head_cache;
            tail_cache -> next = add_member;
            head_cache -> prev = add_member;
            add_member -> prev = tail_cache;
            head_cache = add_member;

            tail_cache -> prev -> next = head_cache;
            head_cache -> prev = tail_cache -> prev;
            delete tail_cache;
            tail_cache = head_cache -> prev;
            chunk_container.erase(mid_code); //delete the tail member in the R-BTree
            return 1;
        }
        else{ //cache contained more than one member

            add_member -> code = mid_code;
            add_member -> next = head_cache;
            tail_cache -> next = add_member;
            head_cache -> prev = add_member;
            add_member -> prev = tail_cache;
            head_cache = add_member;
            cache_size++;
            return 1;
        }
    }

}

int cache::cache_find(char *code, char *chunk_reference, int code_length) {
    std::string mid_string;
    code[code_length] = '\0';
    mid_string = code;
    if(chunk_container[mid_string] != NULL){ //ecc exist
        struct Code_chunk *chunk_info = NULL;
        chunk_info = chunk_container[mid_string];
        if(comp_chunk(chunk_reference, chunk_info)){//chunk exist
            if(!cache_update(code, code_length)) { //update cache error
                std::cout << "cache update error!" << std::endl;
                exit(-1);
            }
            return 1;
        }
        else{
            struct Code_chunk *new_code_chunk = NULL;
            new_code_chunk = new Code_chunk;
            memcpy(new_code_chunk -> chunk, chunk_reference, CHUNK_SIZE);
            new_code_chunk -> next = chunk_info;
            chunk_container[mid_string] = new_code_chunk;
            if(!cache_update(code, code_length)) { //update cache error
                std::cout << "cache update error!" << std::endl;
                exit(-1);
            }
            return 2; // ecc crash happened
        }
    }
    else{ //the ecc is not in the cache, so insert it into the cache
        if(!cache_insert(code, chunk_reference, code_length)){//insert error
            std::cout<<"cache insert error!"<<std::endl;
            exit(-1);
        }
        return 0;
    }
}

int cache::comp_chunk(char *Chunk_reference, struct Code_chunk *chunk_info) {
    struct Code_chunk *p = chunk_info;
    while(p!=NULL){
        if(!memcmp(Chunk_reference, p -> chunk, CHUNK_SIZE)){ //chunk exist
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int cache::cache_update(char *code, int code_length) {
    struct cache_list *mid_member = head_cache;
    if(cache_size == 1)
        return 1;
    else if(cache_size == 2){
        std::string mid_str;

        code[code_length] = '\0';
        mid_str = code;
        if(mid_str.compare(head_cache -> code) == 0)
            return 1;
        else if(mid_str.compare(tail_cache -> code) == 0){
            tail_cache -> code = head_cache -> code;
            head_cache -> code = mid_str;
            return 1;
        }
        else
            return 0;
    }
    else {
        std::string mid_str;
        code[code_length] = '\0';
        mid_str = code;
        while (mid_member->next != head_cache) { //the member is not tail member
            if(mid_str.compare(mid_member -> code) == 0){
                if(mid_member == head_cache)
                    return 1;
                else if(mid_member == tail_cache){
                    head_cache = tail_cache;
                    tail_cache = tail_cache -> prev;
                    return 1;
                }
                else {
                    mid_member->prev->next = mid_member->next;
                    mid_member->next->prev = mid_member->prev;

                    mid_member->next = head_cache;
                    tail_cache->next = mid_member;
                    head_cache->prev = mid_member;
                    mid_member->prev = tail_cache;
                    head_cache = mid_member;
                    return 1;
                }
            }
            else
                mid_member = mid_member -> next;
        }
        return 0;
    }
}




