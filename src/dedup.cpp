//
// Created by victor on 6/1/17.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <iomanip>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include "dedup.h"


#include "com_t.h"


dedup::dedup() {
    chunk_num = 0;
    time_total = 0.0;
    time_aver = 0.0;
    chunk_not_dup = 0;
    block_id = 0;
    head_10000_time = 0.0;

    fade_crash_number = 0;
    crash_number = 0;
    mp = mt::Get_mt();
    cac = cache::Get_cache();
    blf = bloom::Get_bloom();
    cra_t = NULL;
    bch = init_bch(CONFIG_M, CONFIG_T, 0);

    std::cout<<"************************************************************************************"
             <<"test start!"
             <<"************************************************************************************"<<std::endl;
    /*std::cout<<std::left<<std::setw(100)<<"Filename"
             <<std::left<<std::setw(30)<<"Total time(ms)"
             <<std::left<<std::setw(30)<<"Chunk number"
             <<std::left<<std::setw(30)<<"Average time(ms)"<<std::endl;*/
    std::cout<<std::left<<std::setw(30)<<"Block Number"
             <<std::left<<std::setw(30)<<"10000 Average Time(ms)"
             <<std::left<<std::setw(30)<<"Dedup Ratio(%)"
             <<std::left<<std::setw(30)<<"Average Time(ms)"
             <<std::left<<std::setw(30)<<"Total Time(s)"<<std::endl;
}

dedup::~dedup() {
    if(time_total > 0) {
        time_aver = time_total / chunk_num;
        std::cout <<std::endl<< "**************************"<<"This option's time performance***********************"<<std::endl;
//        mt *mp = mt::Get_mt();
//        std::cout<< "write average time is: " << mp->time_total / mp->write_time << std::endl;
        std::cout << "The total time is " << time_total <<"ms"<< std::endl;
        std::cout << "The chunk number is " << chunk_num << std::endl;
        if(chunk_not_dup > 0){
            std::cout << "The dedupe rate is " <<  (chunk_num - chunk_not_dup) * 100.0 / chunk_num <<"%"<<std::endl;
            std::cout << "The not dedupe chunk number is " << chunk_not_dup << std::endl;
        }

        std::cout << "The average time is " << time_aver <<"ms"<< std::endl<<std::endl;
        test_all_crash();
        std::cout << "Fade crash number is " << fade_crash_number << std::endl;
        std::cout << "Crash number is " << crash_number << std::endl;
    }
}

int dedup::dedup_func(char *path) {
    travel_dir(path);

//    std::cout<<"1"<<std::endl;
    return 0;
}

void dedup::travel_dir(char *path) {
    DIR *pdir;
    struct dirent *ent;
    char child_path[512];
    pdir = opendir(path);
    if(pdir == NULL){
        std::cout<<"Open dir error!"<<std::endl;
        exit(-1);
    }

//    std::cout<<"1"<<std::endl;
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
    int mt_flag = 0;
    double stat_t = 0.0;
    double end_t = 0.0;
    char blk_num_str[30];
    cp_t ti;

    if((fp = fopen(path, "r")) == NULL){
        std::cout<<"Open file error!The file name is: "<<path<<std::endl;
        return 0;
    }
    while(1){
        memset(chk_cont, 0, READ_LENGTH);
        if(fread(chk_cont, sizeof(char), READ_LENGTH, fp) == 0)
            break;
        chunk_num++;
        block_id ++;
        if(block_id % 10000 == 0){
            sprintf(blk_num_str, "%ld-%ld", block_id - 10000, block_id - 1);
            std::cout.setf(std::ios::fixed);
            std::cout<<std::left<<std::setw(30)<< blk_num_str
                     <<std::left<<std::setw(30)<< (time_total - head_10000_time) / 10000
                     <<std::left<<std::setw(30)<< (chunk_num - chunk_not_dup) * 100.0 / chunk_num
                     <<std::left<<std::setw(30)<< time_total / chunk_num
                     <<std::left<<std::setw(30)<< time_total / 1000 <<std::endl;
            head_10000_time = time_total;
        }
        memset(hv, 0, CODE_LENGTH + 1);
        memset(bch_result, 0, 2 * CODE_LENGTH + 1);
        encode_bch(bch, chk_cont, READ_LENGTH, hv); //get bch code from a block reference



////////////////////////////////////////////////////////////////////////////////


//        stat_t = ti.get_time();
//        MD5((unsigned char *)chk_cont, (size_t)4096, (unsigned char *)hv);
//        end_t = ti.get_time();
//        ti.cp_all((end_t - stat_t) * 1000, 0);
        /////////////////////////////////////////////////////////////
        ByteToHexStr(hv, bch_result, CODE_LENGTH);
        bloom_flag = dedup_bloom(bch_result, 2 * CODE_LENGTH);
        /////////////////////////////////////////////////////////////
        stat_t = ti.get_time();
//        cache_flag = dedup_cache(bch_result, (char *)chk_cont, 2 * CODE_LENGTH, bloom_flag);
        mt_flag = dedup_mt(bch_result, (char *)chk_cont, 2 * CODE_LENGTH, cache_flag, bloom_flag);
        end_t = ti.get_time();
        if(mt_flag == 2){
            chunk_not_dup++;
            write_block(mp -> alloc_addr_point - 1, (char *)chk_cont);
            //ti.cp_all(0.2, 0);
            time_total += 0.2;
        }


        //ti.cp_all((end_t - stat_t) * 1000, 1);
        time_total += (end_t - stat_t) * 1000;
//        dedup_process(bch_result, (char *)chk_cont, 2 * CODE_LENGTH);


    }
    //ti.cp_aver(path);
    //time_total += ti.time_total;
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

//            chunk_not_dup++; //count the block that not deduplicate
            if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)){
                return 1;
            }
            else{
                std::cout<<"insert mt error!"<<std::endl;
                exit(-1);
            }
        }
        else{

            struct addr *head_addr = NULL;
            char read_buf[READ_LENGTH+1];
            head_addr = mp -> Get_addr(bch_result, bch_lengh);
            if(head_addr == NULL){ //ecc and its' block is not in the mt table
//                chunk_not_dup++; //count the block that not deduplicate
                if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)){
                    return 1;
                }
            }
            else{ //ecc exist, so we need read the block from ssd
                while(head_addr != NULL){
                    memset(read_buf, 0, READ_LENGTH+1);
                    std::cout << "1" << std::endl;
                    read_block(head_addr, read_buf);
                    if(memcmp(read_buf, chk_cont, READ_LENGTH) == 0){ //chunk exist
                        return 1;
                    }
                    head_addr = head_addr -> next;
                }
//                chunk_not_dup++; //count the block that not deduplicate
                if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)) //insert succeed
                    return 1;
                else
                    return 0;
            }
        }
    }
    else{

        cac -> cache_insert(bch_result, chk_cont, bch_lengh); //insert the block into the cache
//        chunk_not_dup++; //count the block that not deduplicate
        if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)) //insert succeed
            return 1;
        else
            return 0;
    }
    return 0;
}

int dedup::dedup_bloom(char *bch_result, int bch_length) {

    std::string str;
    bch_result[bch_length] = '\0';
    str = bch_result;
    if(blf -> bloom_exist(str)) { //the str is exist in the bloom filter
        return 1;
    }
    else
        return 0;

}

int dedup::dedup_cache(char *bch_result, char *chk_cont, int bch_length, int bloom_flag) {


    if(bloom_flag == 1) {
        int res = cac -> cache_find(bch_result, chk_cont, bch_length);
        if (res == 1) {
            return 1;
        } /*else if (res == 2) {
            return 2;  //ecc crash
        }*/ else {
            return 3; //cache missed
        }
    }
    else{//it is also means that the block is not in the mapping table.
        cac -> cache_insert(bch_result, chk_cont, bch_length); //insert the block into the cache
        return 4; //bloom missed
    }
}

int dedup::dedup_mt(char *bch_result, char *chk_cont, int bch_lengh, int cache_flag, int bloom_flag){
    int mid_crash_num = 0;
    if(bloom_flag == 1 && cache_flag != 4) { //bloom hit
        if (cache_flag == 1) { //cache hit
            return 1;
        }
        else if (cache_flag == 2) {//cache crash

            if (mp->insert_mt(bch_result, chk_cont, bch_lengh)) {
                return 2;
            }
            else {
                std::cout << "insert mt error!" << std::endl;
                exit(-1);
            }
        }
        else {//cache missed

            struct addr *head_addr = NULL;
            char read_buf[READ_LENGTH+1];
            head_addr = mp -> Get_addr(bch_result, bch_lengh);
            if(head_addr == NULL){ //ecc and its' block is not in the mt table
//                chunk_not_dup++; //count the block that not deduplicate
                if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)){
                    return 2;
                }
                else{
                    std::cout << "insert mt error!" << std::endl;
                    exit(-1);
                }
            }
            else{ //ecc exist, so we need read the block from ssd
                while(head_addr != NULL){
                    memset(read_buf, 0, READ_LENGTH+1);
                    read_block(head_addr, read_buf);
                    mid_crash_num ++;
                    if(memcmp(read_buf, chk_cont, READ_LENGTH) == 0){ //chunk exist
                        return 1;
                    }
                    head_addr = head_addr -> next;
                }
//                chunk_not_dup++; //count the block that not deduplicate
                if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)){ //insert succeed and ecc crash
                    struct crash_test *cp = NULL;
                    cp = new crash_test;
                    memcpy(cp -> reference1, read_buf, READ_LENGTH);
                    memcpy(cp -> reference2, chk_cont, READ_LENGTH);
                    cp -> next = cra_t;
                    cra_t = cp;
                    fade_crash_number += mid_crash_num;
                    return 2;
                }
                else{
                    std::cout << "insert mt error!" << std::endl;
                    exit(-1);
                }
            }
        }
    }
    else{ //bloom missed

        //cac -> cache_insert(bch_result, chk_cont, bch_lengh); //insert the block into the cache
//        chunk_not_dup++; //count the block that not deduplicate
        if(mp -> insert_mt(bch_result, chk_cont, bch_lengh)) //insert succeed
            return 2;
        else{
            std::cout << "insert mt error!" << std::endl;
            exit(-1);
        }
    }
}

int dedup::test_crash(char *reference1, char *reference2) {
    uint8_t hv1[CODE_LENGTH + 1];
    uint8_t hv2[CODE_LENGTH + 1];

    encode_bch(bch, (unsigned char *)reference1, READ_LENGTH, hv1);
    encode_bch(bch, (unsigned char *)reference2, READ_LENGTH, hv2);


    if(memcmp(reference1, reference2, BLOCK_SIZE) != 0){
        if(memcmp(hv1, hv2, CODE_LENGTH) == 0){
            crash_number ++;
            return 0;
        }
    }

    return 0;
}

int dedup::test_all_crash() {
    struct crash_test *p = cra_t;
    while(p != NULL){
        test_crash(p -> reference1, p ->reference2);
        p = p -> next;
    }
    return 0;
}


