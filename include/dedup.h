//
// Created by victor on 6/1/17.
//

#ifndef ED_DEDUP_H
#define ED_DEDUP_H

#include <stdint.h>
#include "bch.h"

#define READ_LENGTH 4096
#define CONFIG_M 8
#define CONFIG_T 13
#define CODE_LENGTH 16
class dedup{
public:
    dedup();
    ~dedup();

    void travel_dir(char path[]);
    int dedup_func(char path[]);
    int file_reader(char path[]);
    int dedup_process(char bch_result[], char *chk_cont, int bch_length);
    uint64_t chunk_num;
    double time_total;
    double time_aver;
    uint64_t chunk_not_dup;

private:

    void ByteToHexStr(const unsigned char* source, char* dest, int sourceLen);
    struct bch_control *bch;
    int dedup_bloom(char bch_result[], int bch_length);
    int dedup_cache(char bch_result[], char *chk_cont, int bch_length);
    int dedup_mt(char bch_result[], char *chk_cont, int bch_length, int cache_flag);

};


#endif //ED_DEDUP_H
