//
// Created by Adam Dad on 22/08/2022.
//

#ifndef JOLT_CONSTANTPOOL_H
#define JOLT_CONSTANTPOOL_H


#include <vector>
#include "constant.h"

class ConstantPool {
public:
    ConstantPool();

    std::vector<Constant> get_cp_list() const;

    const Constant& get_const(int index);

    std::vector<Constant> cp_list;
};


#endif //JOLT_CONSTANTPOOL_H
