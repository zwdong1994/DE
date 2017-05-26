//
// Created by victor on 5/24/17.
//

#include <string.h>
#include <iostream>
#include <map>
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

int cache::cache_insert(char *code, char *Chunk_reference, int code_length) {
    return 0;
}

int cache::cache_find(char *code, char *chunk_reference, int code_length) {
    std::string mid_string;
    code[code_length] = '\0';
    mid_string = code;
    if(chunk_container[mid_string] != NULL){ //ecc exist
        struct Code_chunk *chunk_info;
        chunk_info = chunk_container[mid_string];
        if(comp_chunk(chunk_reference, chunk_info))  //chunk exist
            return 1;
        else{
            struct Code_chunk *new_code_chunk;
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
        if(memcmp(Chunk_reference, p -> chunk, CHUNK_SIZE)){ //chunk exist
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int cache::cache_update(char *code, int code_length) {
    return 0;
}




