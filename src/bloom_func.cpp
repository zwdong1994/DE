//
// Created by victor on 5/22/17.
//

#include "bloom_func.h"
#include <iostream>
#include <string>
#include <iomanip>

bloom::bloom() {

}

bloom::~bloom() {

}

bloom* bloom::bloom_instance = NULL;

bloom* bloom::Get_bloom() {
    static pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
    if(bloom_instance == NULL){
        pthread_mutex_lock(&mu);
        if(bloom_instance == NULL){
            bloom_instance = new bloom();
        }
        pthread_mutex_unlock(&mu);
    }
    return bloom_instance;
}

int bloom::init_bloom(int element_count, double false_positive_prob) {
    para.projected_element_count = 10000000;
    para.false_positive_probability = 0.000001;
    para.random_seed = 0xA5A5A5A5;

    if(!para){
        std::cout<<"Invalid bloom filter parameters!"<<std::endl;
        return -1;
    }

    bloom_filter filter(para);
    bloom_fil_instance = filter;
    return 1;
}

