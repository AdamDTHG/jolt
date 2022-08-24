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

#define DEBUG_PRINT_HEX(val) \
    print_hex(val)

void print_buffer(std::vector<unsigned char> const& data) {
    for (auto d : data) {
        std::cout << std::hex << std::uppercase << "DEBUG BUFFER -> 0x" << (int) d
        << "\n";
    }
}

//    template<typename T>
void print_hex(int val) {
    std::cout << std::hex << std::uppercase << val << "\n";
}

}
#endif //JOLT_DEBUG_H
