// parser.cpp
// Parse a java classfile
// Created by Adam Dad on 21/08/2022.
//

#include "parser.h"

#define DEBUG_MODE

/**
 * Parse a Java Classfile
 * @param data_buffer
 */
void Parser::parse(std::vector<unsigned char> const& data_buffer) {
    const auto magic = u4(data_buffer);
    const auto major = u2(data_buffer);
    const auto minor = u2(data_buffer);
    const auto constpoolsize = u2(data_buffer);
    const auto cpool = cpinfo(data_buffer, constpoolsize);
#ifdef DEBUG_MODE
    std::cout << "magic: " << std::hex << magic << "\n";
    std::cout << "major: " << std::hex << major << "\n";
    std::cout << "minor: " << std::hex << minor << "\n";
    std::cout << "const pool size: " << constpoolsize << "\n";
    for (const auto& constant : cpool.get_cp_list()) {
        std::cout << "DEBUG CONSTANT -> " << constant.string_literal << "\n";
    }
#endif
}

/**
 * Read 1 byte
 * @param data_buffer
 * @return
 */
unsigned char Parser::u(std::vector<unsigned char> const &data_buffer) {
    int idx = current_index;
    current_index++;
    return data_buffer[idx];
}

/**
 * Read 2 bytes
 * @param data_buffer
 * @return
 */
uint16_t Parser::u2(std::vector<unsigned char> const &data_buffer) {
    int idx = current_index;
    current_index+=2;
    return (data_buffer[idx] << 8) | (data_buffer[idx+1]);
}

/**
 * Read 4 bytes
 * @param data_buffer
 * @return
 */
uint32_t Parser::u4(std::vector<unsigned char> const &data_buffer) {
    int idx = current_index;
    current_index+=4;
    return (data_buffer[idx] << 24) | (data_buffer[idx+1] << 16) | (data_buffer[idx+2] << 8) | (data_buffer[idx+3]);
}

ConstantPool Parser::cpinfo(std::vector<unsigned char> const& data_buffer, int const& cp_max_size) {
    ConstantPool constpool;
    while (constpool.cp_list.size() < cp_max_size - 1) {
        constpool.cp_list.push_back(parse_constant(data_buffer));
    }
    return constpool;
}

Constant Parser::parse_constant(std::vector<unsigned char> const& data_buffer) {
    Constant c {0, "", 0, 0, 0, 0, 0};
    c.tag = u(data_buffer);
    switch (c.tag) {
        case 0x01:{
            c.string_literal = string_literal(data_buffer);
            break;
        }
        case 0x07: { // Class Index
            c.name_index = u2(data_buffer);
            break;
        }
        case 0x08: { // String reference Index
            c.string_index = u2(data_buffer);
            break;
        }
        case 0x09: case 0x0A: { // Field and Method
            c.class_index = u2(data_buffer);
            c.name_and_type_index = u2(data_buffer);
            break;
        }
        case 0x0c: { // Name and Type
            c.name_index = u2(data_buffer);
            c.desc_index = u2(data_buffer);
            break;
        }
        default: {
            std::cerr << "Unknown Constant Tag -> 0x" << std::hex << std::uppercase << (int) c.tag << "\n";
            break;
        }
    }
    return c;
}

std::string Parser::string_literal(std::vector<unsigned char> const& data_buffer) {
    auto string_len = u2(data_buffer);
    std::string str;
    while (str.length() < string_len) {
        str.push_back(u(data_buffer));
    }
    return str;
}