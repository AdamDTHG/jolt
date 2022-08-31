//
// Created by Adam Dad on 22/08/2022.
//

#ifndef JOLT_CONSTANTPOOL_H
#define JOLT_CONSTANTPOOL_H


#include <vector>
#include "constant.h"

class ConstantPool {
public:
    explicit ConstantPool(const std::vector<Constant> &pool);

    std::vector<Constant> get_pool() const;

    const Constant& get_const(int index);

private:
    std::vector<Constant> pool;
};


#endif //JOLT_CONSTANTPOOL_H
