//
// Created by Adam Dad on 22/08/2022.
//

#include "constantpool.h"
#include "parser.h"

ConstantPool::ConstantPool(const std::vector<Constant> &pool) : pool(pool) {}

std::vector<Constant> ConstantPool::get_pool() const {
    return pool;
}

Constant const& ConstantPool::get_const(int index) {
    return pool[index];
}

