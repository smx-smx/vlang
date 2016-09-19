/*
 * Expression.cpp
 * Copyright (C) 2016 Nemanja Mićović <nmicovic@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "Expression.hpp"

// Required in order to use lexical cast
namespace boost{
    void throw_exception(std::exception const &e){(void)(e);}
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
namespace vlang {
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

std::string ConstIntExprAST::dump(unsigned) const {
    return boost::lexical_cast<std::string>(m_val);
}

std::string ConstDoubleExprAST::dump(unsigned) const {
    return boost::lexical_cast<std::string>(m_val);
}

std::string StringExprAST::dump(unsigned) const {
    return "\"" + m_str + "\"";
}

std::string UnaryExprAST::dump(unsigned) const {
    return m_operation + m_operand->dump();
}

std::string BinaryExprAST::dump(unsigned) const {
    return m_left->dump() + " " + m_operation + " " + m_right->dump();
}

std::string VariableExprAST::dump(unsigned) const {
    return boost::lexical_cast<std::string>(m_name);
};

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
} // ;vlang
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
