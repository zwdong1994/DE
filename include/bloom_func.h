//
// Created by victor on 5/22/17.
//

#ifndef ED_BLOOM_FUNC_H
#define ED_BLOOM_FUNC_H

#include "bloom_filter.hpp"
class bloom{
private:
    bloom();
    bloom(bloom const&);
    bloom& operator=(bloom const&);
    ~bloom();
    bloom_parameters para;
    int init_bloom(int element_count, double false_positive_prob);
    bloom_filter bloom_fil_instance;

public:
    static bloom *Get_bloom();
    static bloom *bloom_instance;

};
#endif //ED_BLOOM_FUNC_H
