/*
 * Types.cpp
 * Copyright (C) 2016 Nemanja Mićović <nmicovic@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "Types.hpp"

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
namespace vlang {
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// INT32
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
std::string Int32Type::str() const {
    return "int";
}

VLANG_TYPE Int32Type::vlang_type() const {
    return VLANG_TYPE::INT32;
}

Type* Int32Type::llvm_type() const {
    return LLVM_INTTY;
}

int Int32Type::strength() const {
    return 20;
}
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// DOUBLE TYPE
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
std::string DoubleType::str() const {
    return "double";
}

VLANG_TYPE DoubleType::vlang_type() const {
    return VLANG_TYPE::DOUBLE;
}

Type* DoubleType::llvm_type() const {
    return LLVM_DOUBLETY;
}

int DoubleType::strength() const {
    return 30;
}
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// STRING TYPE
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
std::string StringType::str() const {
    return "string";
}

Type* StringType::llvm_type() const {
    std::cerr << "TODO: StringType::llvm_type()" << std::endl;
    return nullptr;
}

VLANG_TYPE StringType::vlang_type() const {
    return VLANG_TYPE::STRING;
}

int StringType::strength() const {
    return 40;
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// BOOL TYPE
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
std::string BoolType::str() const {
    return "bool";
}

Type* BoolType::llvm_type() const {
    std::cerr << "TODO: BoolType::llvm_type()" << std::endl;
    return nullptr;
}

VLANG_TYPE BoolType::vlang_type() const {
    return VLANG_TYPE::BOOL;
}

int BoolType::strength() const {
    return 10;
}
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// UTILS
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
std::string to_str(VLANG_TYPE type) {
    switch (type) {
        case INT32:
            return "int";
        case INT64:
            return "int64";
        case DOUBLE:
            return "double";
        case BOOL:
            return "bool";
        case STRING:
            return "string";
        case VOID:
            return "void";
        default:
            return "unknown_type";
    }
}

std::string to_str(Type* llvm_type) {
    if (llvm_type == LLVM_INTTY)
        return "int";
    else if (llvm_type == LLVM_DOUBLETY)
        return "double";
    else
        return "unknown_type";
}

VlangType* make_from_enum(VLANG_TYPE type) {
    switch (type) {
        case VLANG_TYPE::INT32:
            return new Int32Type();
        case VLANG_TYPE::DOUBLE:
            return new DoubleType();
        case VLANG_TYPE::STRING:
            return new StringType();
        default:
            std::cerr << "What is this type? " << to_str(type) << std::endl;
            return nullptr;
    }
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
} // ;vlang
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
