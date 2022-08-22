//
// Created by Adam Dad on 21/08/2022.
//

#ifndef JOLT_PARSER_H
#define JOLT_PARSER_H


#include <vector>

class parser {
public:
    parser() = default;

    void parse(const std::vector<unsigned char> &data_buffer);

private:
    int current_index = 0;
    int u(const std::vector<unsigned char> &data_buffer);

    uint16_t u2(const std::vector<unsigned char> &data_buffer);

    uint32_t u4(const std::vector<unsigned char> &data_buffer);

    uint64_t u8(const std::vector<unsigned char> &data_buffer);
};


#endif //JOLT_PARSER_H
