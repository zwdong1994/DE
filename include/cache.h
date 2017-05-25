//
// Created by victor on 5/24/17.
//

#ifndef ED_CACHE_H
#define ED_CACHE_H

class cache{
private:
    cache();
    cache(cache const&);
    cache &operator = (cache const&);
    ~cache();
    std::map<std::string, std::string> chunk_container; //save(ECC code, Chunk_reference)
    struct cache_list{
        std::string append_ecc_code;  //ecc+exist_number(exist_number:0 represent not repetition, 1...n represent exist number)
        struct cache_list *next;
    }*head_cache;

public:
    static cache *Get_cache();
    static cache *cache_instance;
    int cache_insert(char ECC_code[], char Chunk_reference[], int ECC_length);
};


#endif //ED_CACHE_H

