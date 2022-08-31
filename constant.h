//
// Created by Adam Dad on 23/08/2022.
//

#ifndef JOLT_CONSTANT_H
#define JOLT_CONSTANT_H


#include <string>

class Constant {
public:
    explicit Constant(unsigned char tag = 0x00, const std::string &stringLiteral = "", uint16_t nameIndex = 0, uint16_t stringIndex = 0,
             uint16_t classIndex = 0, uint16_t nameAndTypeIndex = 0, uint16_t descIndex = 0);

    virtual unsigned char getTag() const;

    const std::string &getStringLiteral() const;

    uint16_t getNameIndex() const;

    uint16_t getStringIndex() const;

    uint16_t getClassIndex() const;

    uint16_t getNameAndTypeIndex() const;

    uint16_t getDescIndex() const;

private:
    unsigned char tag;
    std::string string_literal;
    uint16_t name_index;
    uint16_t string_index;
    uint16_t class_index;
    uint16_t name_and_type_index;
    uint16_t desc_index;
};


#endif //JOLT_CONSTANT_H
