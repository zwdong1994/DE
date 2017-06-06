//
// Created by victor on 6/6/17.
//

#include "dedup.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

void random_string(char str[], int length){
    int i;
    for(i = 0; i < length; i++){
        str[i] = 'a' + (rand() % 26);
    }
    str[length] = '\0';
}

int main(){
    char path[256] = "/mnt/cdrom/vmdk";
    dedup ded;



/////////////////////////////////////////////////////////////////////////////
///                              test travel                              ///
/////////////////////////////////////////////////////////////////////////////
    ded.travel_dir(path);
    return 0;
}