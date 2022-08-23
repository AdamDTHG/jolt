//
// Created by Adam Dad on 22/08/2022.
//

#include "constantpool.h"

constantpool::constantpool(std::vector<unsigned char> const& data_buffer, int const& n_bytes, long const& current_index = 0) {
    long i = current_index;
    for(i; i<n_bytes+1; i++) {
        cp_list.push_back(data_buffer[i]);
    }
}

std::vector<unsigned char> const& constantpool::get_cp_list() const {
    return cp_list;
}

unsigned char const& constantpool::get_const(int index) {
    return cp_list[index];
}
