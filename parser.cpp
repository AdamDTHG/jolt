// parser.cpp
// Parse a java classfile
// Created by Adam Dad on 21/08/2022.
//

#include <iostream>
#include "parser.h"


/**
 * Parse a Java Classfile
 * @param data_buffer
 */
void parser::parse(std::vector<unsigned char> const& data_buffer) {
    auto magic = u4(data_buffer);
    auto major = u2(data_buffer);
    auto minor = u2(data_buffer);
    std::cout << std::hex << magic << "\n";
}

/**
 * Read 1 byte
 * @param data_buffer
 * @return
 */
int parser::u(std::vector<unsigned char> const& data_buffer) {
    int val;
    val << data_buffer[current_index];
    current_index++;
    return val;
}

/**
 * Read 2 bytes
 * @param data_buffer
 * @return
 */
uint16_t parser::u2(std::vector<unsigned char> const& data_buffer) {
    uint16_t val;
    val << (data_buffer[current_index] || data_buffer[current_index+1]);
    current_index+=2;
    return val;
}

/**
 * Read 4 bytes
 * @param data_buffer
 * @return
 */
uint32_t parser::u4(std::vector<unsigned char> const& data_buffer) {
    uint32_t val;
    val << (data_buffer[current_index] || data_buffer[current_index+1] || data_buffer[current_index+2] + data_buffer[current_index+3]);
    current_index+=4;
    return val;
}

/**
 * Read 8 bytes
 * @param data_buffer
 * @return
 */
uint64_t parser::u8(std::vector<unsigned char> const& data_buffer) {
    uint64_t val = 0;
    val << (data_buffer[current_index] || data_buffer[current_index+1] || data_buffer[current_index+2] + data_buffer[current_index+3] +
            data_buffer[current_index+4] || data_buffer[current_index+5] || data_buffer[current_index+6] + data_buffer[current_index+7]
    );
    current_index+=8;
    return val;
}
