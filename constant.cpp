//
// Created by Adam Dad on 23/08/2022.
//

#include "constant.h"

#include <utility>

Constant::Constant(unsigned char tag, const std::string &stringLiteral, uint16_t nameIndex, uint16_t stringIndex,
                   uint16_t classIndex, uint16_t nameAndTypeIndex, uint16_t descIndex) : tag(tag),
                                                                                         string_literal(stringLiteral),
                                                                                         name_index(nameIndex),
                                                                                         string_index(stringIndex),
                                                                                         class_index(classIndex),
                                                                                         name_and_type_index(
                                                                                                 nameAndTypeIndex),
                                                                                         desc_index(descIndex) {}

const std::string &Constant::getStringLiteral() const {
    return string_literal;
}

uint16_t Constant::getNameIndex() const {
    return name_index;
}

uint16_t Constant::getStringIndex() const {
    return string_index;
}

uint16_t Constant::getClassIndex() const {
    return class_index;
}

uint16_t Constant::getNameAndTypeIndex() const {
    return name_and_type_index;
}

uint16_t Constant::getDescIndex() const {
    return desc_index;
}

unsigned char Constant::getTag() const {
    return tag;
}