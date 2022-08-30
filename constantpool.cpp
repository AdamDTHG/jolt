//
// Created by Adam Dad on 22/08/2022.
//

#include "constantpool.h"
#include "parser.h"

ConstantPool::ConstantPool() {}

std::vector<Constant> ConstantPool::get_cp_list() const {
    return cp_list;
}

Constant const& ConstantPool::get_const(int index) {
    return cp_list[index];
}
