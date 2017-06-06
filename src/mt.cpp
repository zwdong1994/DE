//
// Created by victor on 6/2/17.
//

#include "mt.h"

#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



mt::mt() {
    ssd_capacity = 64;
    max_size_addr = ssd_capacity * 1024 * 1024 / 4;
    alloc_addr_point = 0;
    dev_name = new char[30];
    strcpy(dev_name, "/dev/sdc1");
    fd = open(dev_name, O_RDWR|O_LARGEFILE);
    if(fd == -1){
        std::cout<<"open "<< dev_name <<" error!"<<std::endl;
        exit(-1);
    }
}

mt::~mt() {

}

mt* mt::mt_instance = NULL;

mt* mt::Get_mt(){
    static pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
    if(mt_instance == NULL){
        pthread_mutex_lock(&mu);
        if(mt_instance == NULL)
            mt_instance = new mt();
        pthread_mutex_unlock(&mu);
    }
    return mt_instance;
}

struct addr* mt::Get_addr(char *ecc_code, int length_ecc) {
    std::string str;
    ecc_code[length_ecc] = '\0';
    str = ecc_code;
    if(mt_container[str] != NULL){ //exist
        return mt_container[str];
    }
    else
        return NULL;

}

int mt::insert_mt(char *ecc_code, char chunk_reference[], int length_ecc) {
    struct addr *p = NULL;
    p = new addr;

    if(alloc_addr_point < max_size_addr){
        std::string str;
        ecc_code[length_ecc] = '\0';
        str = ecc_code;
        p -> offset = alloc_addr_point;
        p -> next = NULL;
        alloc_addr_point++; //allocate succeed
        if(mt_container[str] != NULL){
            p -> next = (struct addr*)mt_container[str];
            mt_container[str] = p;
            write_block(p, chunk_reference);
            return 1;
        }
        else{
            mt_container[str] = p;
            write_block(p, chunk_reference);
            return 1;
        }

    }
    return 0;
}

int mt::write_block(struct addr *write_addr, char *chunk_reference) {
    struct aiocb64 aio;
    bzero((char *)&aio, sizeof(struct aiocb64));
    aio.aio_buf = malloc(4097);
    if(!aio.aio_buf)
        perror("malloc\n");
    aio.aio_fildes = fd;
    aio.aio_nbytes = BLOCK_SIZE;
    aio.aio_offset = write_addr->offset * BLOCK_SIZE;
    memcpy((void *)aio.aio_buf, (void *)chunk_reference, BLOCK_SIZE);
    aio_write64(&aio);
    while(EINPROGRESS == aio_error64(&aio));

    return 1;
}

int mt::read_block(struct addr *write_addr, char *chunk_reference) {
    struct aiocb64 aio;
    bzero((char *) &aio, sizeof(struct aiocb64));
    aio.aio_buf = malloc(BLOCK_SIZE + 1);
    if (!aio.aio_buf)
        perror("malloc\n");
    aio.aio_fildes = fd;
    aio.aio_nbytes = BLOCK_SIZE;
    aio.aio_offset = write_addr->offset * BLOCK_SIZE;

    aio_read64(&aio);
    while (EINPROGRESS == aio_error64(&aio));
    memset(chunk_reference, 0, BLOCK_SIZE + 1);
    memcpy((void *) chunk_reference, (void *) aio.aio_buf, BLOCK_SIZE);
    return 1;
}
