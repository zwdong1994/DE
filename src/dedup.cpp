//
// Created by victor on 6/1/17.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>

#include "dedup.h"
#include "bloom_func.h"
#include "cache.h"
#include "mt.h"


dedup::dedup() {
    chunk_num = 0;
    time_total = 0.0;
    time_aver = 0.0;
    chunk_not_dup = 0;

    bch = init_bch(CONFIG_M, CONFIG_T, 0);
}

dedup::~dedup() {

}

int dedup::dedup_func(char *path) {
    return 0;
}

void dedup::travel_dir(char *path) {
    DIR *pdir;
    struct dirent *ent;
    char child_path[512];
    pdir = opendir(path);


    while((ent = readdir(pdir)) != NULL){
        memset(child_path, 0, 512);
        if(ent->d_type & DT_DIR){ //if the ent is dir
            if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;
            sprintf(child_path,"%s/%s",path,ent->d_name);
            travel_dir(child_path);
        }
        else{
            sprintf(child_path,"%s/%s",path,ent->d_name);
//            std::cout<<child_path <<std::endl;
            file_reader(child_path);
        }
    }
}

int dedup::file_reader(char *path) {
    uint8_t hv[CODE_LENGTH + 1];
    char bch_result[2 * CODE_LENGTH + 1];
    FILE *fp = NULL;
    uint8_t chk_cont[4097];
    int bloom_flag = 0;
    int cache_flag = 0;

    if((fp = fopen(path, "r")) == NULL){
        std::cout<<"Open file error!The file name is: "<<path<<std::endl;
        return 0;
    }
    while(1){
        memset(chk_cont, 0, READ_LENGTH);
        if(fread(chk_cont, sizeof(char), READ_LENGTH, fp) == 0)
            break;
        memset(hv, 0, CODE_LENGTH + 1);
        memset(bch_result, 0, 2 * CODE_LENGTH + 1);
        encode_bch(bch, chk_cont, READ_LENGTH, hv); //get bch code from a block reference
        ByteToHexStr(hv, bch_result, CODE_LENGTH);
        chunk_num++;
////////////////////////////////////////////////////////////////////////////////
        bloom_flag = (bch_result, 2 * CODE_LENGTH);
        dedup_process(bch_result, (char *)chk_cont, 2 * CODE_LENGTH);


    }
    fclose(fp);
    return 0;
}

void dedup::ByteToHexStr(const unsigned char *source, char *dest, int sourceLen) {
    short i;
    unsigned char highByte, lowByte;

    for (i = 0; i < sourceLen; i++)
    {
        highByte = source[i] >> 4;
        lowByte = source[i] & 0x0f ;

        highByte += 0x30;

        if (highByte > 0x39)
            dest[i * 2] = highByte + 0x07;
        else
            dest[i * 2] = highByte;

        lowByte += 0x30;
        if (lowByte > 0x39)
            dest[i * 2 + 1] = lowByte + 0x07;
        else
            dest[i * 2 + 1] = lowByte;
    }
    return ;
}

int dedup::dedup_process(char *bch_result, char *chk_cont, int bch_lengh) {
    bloom *blf = bloom::Get_bloom();
    std::string str;
    cache *cac = cache::Get_cache();
    bch_result[bch_lengh] = '\0';
    str = bch_result;
    if(blf -> bloom_exist(str)){ //the str is exist in the bloom filter
        int res = cac -> cache_find(bch_result, chk_cont, bch_lengh);
        if(res == 1){
            return 1;
        }
        else if(res == 2){ //ecc crash
            mt *mp = mt::Get_mt();
            chunk_not_dup++; //count the block that not deduplicate
            if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)){
                return 1;
            }
            else{
                std::cout<<"insert mt error!"<<std::endl;
                exit(-1);
            }
        }
        else{
            mt *mp = mt::Get_mt();
            struct addr *head_addr = NULL;
            char read_buf[READ_LENGTH+1];
            head_addr = mp -> Get_addr(bch_result, bch_lengh);
            if(head_addr == NULL){ //ecc and its' block is not in the mt table
                chunk_not_dup++; //count the block that not deduplicate
                if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)){
                    return 1;
                }
            }
            else{ //ecc exist, so we need read the block from ssd
                while(head_addr != NULL){
                    memset(read_buf, 0, READ_LENGTH+1);
                    mp->read_block(head_addr, read_buf);
                    if(memcmp(read_buf, chk_cont, READ_LENGTH) == 0){ //chunk exist
                        return 1;
                    }
                    head_addr = head_addr -> next;
                }
                chunk_not_dup++; //count the block that not deduplicate
                if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)) //insert succeed
                    return 1;
                else
                    return 0;
            }
        }
    }
    else{
        mt *mp = mt::Get_mt();
        cac -> cache_insert(bch_result, chk_cont, bch_lengh); //insert the block into the cache
        chunk_not_dup++; //count the block that not deduplicate
        if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)) //insert succeed
            return 1;
        else
            return 0;
    }
    return 0;
}

int dedup::dedup_bloom(char *bch_result, int bch_length) {
    bloom *blf = bloom::Get_bloom();
    std::string str;
    bch_result[bch_length] = '\0';
    str = bch_result;
    if(blf -> bloom_exist(str)) { //the str is exist in the bloom filter
        return 1;
    }
    else
        return 0;

}

int dedup::dedup_cache(char *bch_result, char *chk_cont, int bch_length) {
    cache *cac = cache::Get_cache();
    int res = cac -> cache_find(bch_result, chk_cont, bch_length);
    if(res == 1){
        return 1;
    }
    else if(res == 2){ //ecc crash
        return 2;
    }
    else{
        return 3; //cache missed
    }

    
}
