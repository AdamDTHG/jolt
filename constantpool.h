//
// Created by Adam Dad on 22/08/2022.
//

#ifndef JOLT_CONSTANTPOOL_H
#define JOLT_CONSTANTPOOL_H


#include <vector>

class constantpool {
public:
    constantpool(const std::vector<unsigned char> &data_buffer, const int &n_bytes, const long &current_index);

    const std::vector<unsigned char> &get_cp_list() const;

    const unsigned char &get_const(int index);

private:
    std::vector<unsigned char> cp_list;

};


#endif //JOLT_CONSTANTPOOL_H
