//
// Created by victor on 6/2/17.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cache.h"

void random_string(char str[], int length){
    int i;
    for(i = 0; i < length; i++){
        str[i] = 'a' + (rand() % 26);
    }
    str[length] = '\0';
}

int main(){
    char *block[1000];
    char *ecc_code[10001];
    char *ecc_crash[100];
    int i;
    for(i = 0; i < 1000; i++){
        block[i] = new char[4096];
        random_string(block[i], 4096);
    }
    for(i = 0; i < 10001; i++){
        ecc_code[i] = new char[33];
        random_string(ecc_code[i], 32);
    }
    for(i = 0; i< 100; i++){
        ecc_crash[i] = new char[33];
        random_string(ecc_crash, 32);
    }
/////////////////////////////////////////////////////////////////////////////
///                              test insert                              ///
/////////////////////////////////////////////////////////////////////////////
    for(i = 0; i < 10001; i++){

    }
    return 0;
}