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
    Parser(const std::vector<unsigned char> &dataBuffer);

    /**
     * parse java classfile
     */
    void parse();


private:
    const std::vector<unsigned char> &data_buffer;
    int current_index{};

    /**
     * Read 1 byte from data_buffer
     * @return
     */
    unsigned char u();

    /**
     * Read 2 bytes
     * @return
     */
    uint16_t u2();

    /**
     * Read 4 bytes
     * @return
     */
    uint32_t u4();

    /**
     * parse a string literal value in bytes
     * @return
     */
    std::string string_literal();

    /**
     * parses constatns in constpool
     * @param cp_max_size
     * @return ConstantPool
     */
    ConstantPool cpinfo(const int &cp_max_size);

    /**
     * Parse a single constant
     * @return Constant
     */
    Constant parse_constant();

};


#endif //JOLT_PARSER_H
