//
// Created by Adam Dad on 21/08/2022.
//

#ifndef JOLT_PARSER_H
#define JOLT_PARSER_H


#include <iostream>
#include <vector>
#include "constantpool.h"
#include "constant.h"


class Parser {
public:
    Parser() = default;

    void parse(const std::vector<unsigned char> &data_buffer);


private:
    int current_index;
    unsigned char u(const std::vector<unsigned char> &data_buffer);

    uint16_t u2(const std::vector<unsigned char> &data_buffer);

    uint32_t u4(const std::vector<unsigned char> &data_buffer);

    std::string string_literal(const std::vector<unsigned char>& data_buffer);

    ConstantPool cpinfo(const std::vector<unsigned char> &data_buffer, const int &cp_max_size);

    Constant parse_constant(const std::vector<unsigned char> &data_buffer);
};


#endif //JOLT_PARSER_H
