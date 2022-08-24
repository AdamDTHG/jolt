//
// Created by Adam Dad on 22/08/2022.
//

#include "constantpool.h"
#include "parser.h"

constantpool::constantpool(std::vector<unsigned char> const& data_buffer, int const& n_bytes, int const& current_index) {
    current_index;
}

std::vector<unsigned char> constantpool::get_cp_list() const {
    return cp_list;
}

unsigned char const& constantpool::get_const(int index) {
    return cp_list[index];
}
