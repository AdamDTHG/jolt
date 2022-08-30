//
// Created by Adam Dad on 22/08/2022.
//

#ifndef JOLT_CONSTANTPOOL_H
#define JOLT_CONSTANTPOOL_H


#include <vector>
#include "constant.h"

class constantpool {
public:
    constantpool();

    std::vector<constant> get_cp_list() const;

    const constant& get_const(int index);

    std::vector<constant> cp_list;
};


#endif //JOLT_CONSTANTPOOL_H
