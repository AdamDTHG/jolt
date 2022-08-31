// parser.cpp
// Parse a java classfile
// Created by Adam Dad on 21/08/2022.
//

#include "parser.h"

#define DEBUG_MODE

Parser::Parser(const std::vector<unsigned char> &dataBuffer)
        : data_buffer(dataBuffer) {
}

void Parser::parse() {
    const auto magic = u4();
    const auto major = u2();
    const auto minor = u2();
    const auto constpoolsize = u2();
    const auto cpool = cpinfo(constpoolsize);
#ifdef DEBUG_MODE
    std::cout << "magic: " << std::hex << magic << "\n";
    std::cout << "major: " << std::hex << major << "\n";
    std::cout << "minor: " << std::hex << minor << "\n";
    std::cout << "const pool size: " << constpoolsize << "\n";
    for (const auto& constant : cpool.get_pool()) {
        std::cout << "DEBUG CONSTANT -> " << constant.getStringLiteral() << "\n";
    }
#endif
}

unsigned char Parser::u() {
    int idx = current_index;
    current_index++;
    return data_buffer[idx];
}

uint16_t Parser::u2() {
    int idx = current_index;
    current_index+=2;
    return (data_buffer[idx] << 8) | (data_buffer[idx+1]);
}

uint32_t Parser::u4() {
    int idx = current_index;
    current_index+=4;
    return (data_buffer[idx] << 24) | (data_buffer[idx+1] << 16) | (data_buffer[idx+2] << 8) | (data_buffer[idx+3]);
}

ConstantPool Parser::cpinfo(int const& cp_max_size) {
    std::vector<Constant> cp;
    while (cp.size() < cp_max_size - 1) {
        cp.push_back(parse_constant());
    }
    return ConstantPool{cp};
}

/**
 * TODO: Refactor this function using a factory method for Constant.
 */
Constant Parser::parse_constant() {
    auto const tag = u();
    switch (tag) {
        case 0x01:{
            auto const string = string_literal();
            return Constant{tag, string};
        }
        case 0x07: { // Class Index
            auto const name_index = u2();
            return Constant{tag, "", name_index};
        }
        case 0x08: { // String reference Index
            auto const string_index = u2();
            return Constant{tag, "", 0, string_index};
        }
        case 0x09: case 0x0A: { // Field and Method
            auto const class_index = u2();
            auto const name_and_type_index = u2();
            return Constant{tag, "", 0, 0, class_index, name_and_type_index};
        }
        case 0x0c: { // Name and Type
            auto const name_index = u2();
            auto const desc_index = u2();
            return Constant{tag, "", name_index, 0, 0, 0, desc_index};
        }
        default: {
            std::cerr << "Unknown Constant Tag -> 0x" << std::hex << std::uppercase << (int) tag << "\n";
        }
    }
}

std::string Parser::string_literal() {
    auto string_len = u2();
    std::string str;
    while (str.length() < string_len) {
        str.push_back(u());
    }
    return str;
}
