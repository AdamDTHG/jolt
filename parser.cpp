// parser.cpp
// Parse a java classfile
// Created by Adam Dad on 21/08/2022.
//

#include "parser.h"


/**
 * Parse a Java Classfile
 * @param data_buffer
 */
void parser::parse(std::vector<unsigned char> const& data_buffer) {
    const auto magic = u4(data_buffer);
    const auto major = u2(data_buffer);
    const auto minor = u2(data_buffer);
    const auto constpoolsize = u2(data_buffer);
//    constantpool cp = constantpool{data_buffer, (int) constpoolsize, current_index};
    std::vector<std::string> cplist = cp(data_buffer);
    for (auto constant : cplist) {
        std::cout << "DEBUG CONSTANT -> " << constant << "\n";
    }
}

/**
 * Read 1 byte
 * @param data_buffer
 * @return
 */
int parser::u(std::vector<unsigned char> const &data_buffer) {
    unsigned char val = data_buffer[current_index];
    current_index++;
    return (int) val;
}

/**
 * Read 2 bytes
 * @param data_buffer
 * @return
 */
uint16_t parser::u2(std::vector<unsigned char> const &data_buffer) {
    uint16_t val = (data_buffer[current_index] << 8) | (data_buffer[current_index+1]);
    current_index+=2;
    return val;
}

/**
 * Read 4 bytes
 * @param data_buffer
 * @return
 */
uint32_t parser::u4(std::vector<unsigned char> const &data_buffer) {
    uint32_t val = (data_buffer[current_index] << 24) | (data_buffer[current_index+1] << 16) | (data_buffer[current_index+2] << 8) | (data_buffer[current_index+3]);
    current_index+=4;
    return val;
}

/**
 * Read 8 bytes
 * @param data_buffer
 * @return
 */
//uint64_t parser::u8(std::vector<unsigned char> const &data_buffer) {
//    uint64_t val = (data_buffer[current_index] << 56) | (data_buffer[current_index+1] << 48) | (data_buffer[current_index+2] << 40) | (data_buffer[current_index+3] << 32) |
//            (data_buffer[current_index+4] << 24) | (data_buffer[current_index+5] << 16) | (data_buffer[current_index+6] << 8) | data_buffer[current_index+7];
//    current_index+=8;
//    return val;
//}


std::vector<std::string> parser::cp(std::vector<unsigned char> const &data_buffer) {
    std::vector<std::string> cp_list;
    while (current_index < data_buffer.size()) {
        auto tag = u(data_buffer);
//        std::cout << "Tag -> " << std::hex << (int) tag << "\n";
        switch (tag) {
            case 0x01:{
                auto val = string_literal(data_buffer);
                cp_list.push_back(val);
            }
            case 0x07: std::cerr << "Not Implemented" << "\n";
            default: std::cerr << "Unknown Constant -> 0x" << std::hex << std::uppercase << (int) tag << "\n";
        }
    }
    return cp_list;
}

std::string parser::string_literal(std::vector<unsigned char> data_buffer) {
    auto string_len = u2(data_buffer);
    std::string val = "";
    int i;
    for (i = 0; i < string_len; i++) {
        char str = (char) u(data_buffer);
        val += str;
    }
    return val;
}