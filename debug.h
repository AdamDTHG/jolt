//
// Created by Adam Dad on 22/08/2022.
//

#ifndef JOLT_DEBUG_H
#define JOLT_DEBUG_H

#include <vector>
#include <ios>
#include <iostream>

namespace dbg {

#define DEBUG_BUFFER(data) \
    print_buffer(data)


void print_buffer(std::vector<unsigned char> const& data) {
    for (auto d : data) {
        std::cout << std::hex << std::uppercase << (int) d
        << "\n";
    }
}

}

#endif //JOLT_DEBUG_H
