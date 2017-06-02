//
// Created by victor on 6/2/17.
//

#ifndef ED_MT_H
#define ED_MT_H

#include <cstdint>
#include <iostream>
#include <map>

#define BLOCK_SIZE 4096
struct addr{
    unsigned long offset; //block address
    struct addr *next;
};
class mt{
public:
    static mt *Get_mt();
    static mt *mt_instance;
    struct addr* Get_addr(char ecc_code[], int length_ecc);  //get the chunk addr from the mt list
    int insert_mt(char ecc_code[], char chunk_reference[], int length_ecc); //insert a new ecc-addr pair to the mt list and in the mean time write the block
    int write_block(struct addr *write_addr, char chunk_reference[]);
    int read_block(struct addr *write_addr, char chunk_reference[]);



private:
    mt();
    mt(mt const&);
    mt &operator = (mt const&);
    ~mt();

    unsigned int ssd_capacity;
    unsigned long max_size_addr; //the maximum block address
    unsigned long alloc_addr_point;
    std::map<std::string, struct addr*> mt_container; //save(ECC or hash code, block address)

    char *dev_name;
    int fd;
};

#endif //ED_MT_H
