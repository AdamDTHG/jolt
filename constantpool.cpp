//
// Created by Adam Dad on 22/08/2022.
//

#include "constantpool.h"
#include "parser.h"

constantpool::constantpool() {}

std::vector<constant> constantpool::get_cp_list() const {
    return cp_list;
}

constant const& constantpool::get_const(int index) {
    return cp_list[index];
}
