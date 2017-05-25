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

int cache::cache_insert(char *ECC_code, char *Chunk_reference, int ECC_length) {
    return 0;
}


