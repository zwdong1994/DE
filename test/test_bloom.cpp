//
// Created by victor on 6/2/17.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "bloom_func.h"

void random_string(char str[], int length){
    int i;
    for(i = 0; i < length; i++){
        str[i] = 'a' + (rand() % 26);
    }
    str[length] = '\0';
}

int main(){
    bloom *bl = bloom::Get_bloom();
    char str1[1000][11];
    char str2[1000][11];
    std::string str;
    int i;
    int exist_time = 0;
    srand((unsigned)time(NULL));
    for( i = 0; i < 1000; i++){
        random_string(str1[i], 10);
    }
    for( i = 0; i < 1000; i++){
        random_string(str2[i], 10);
    }

    

/////////////////////////////////////////////////////////////////////////////
    for( i = 0; i < 1000; i++){
        str = str1[i];
        bl -> bloom_insert(str);
    }

    for( i = 0; i < 1000; i++){
        str = str1[i];
        if(bl -> bloom_exist(str)) {
            std::cout << str << " exist!" << std::endl;
            exist_time++;
        }
        else
            std::cout<< str << " not exist!" << std::endl;
    }
    std::cout<<exist_time<<std::endl;
    exist_time = 0;
////////////////////////////////////////////////////////////////////////////
    for( i = 0; i < 1000; i++){
        str = str2[i];
        if(bl -> bloom_exist(str)) {
            std::cout << str << " exist!" << std::endl;
            exist_time++;
        }
        else
            std::cout<< str << " not exist!" << std::endl;
    }
    std::cout<<exist_time<<std::endl;
    return 0;
}
