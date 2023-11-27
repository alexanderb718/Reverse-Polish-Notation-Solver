// Parser.h
// Alexander Bertholf
// Section 01
// Last Modified 11/8/2021

#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "stack.hpp"

class Parser {
private:
    static int precedence(const std::string& str);
    static bool isNumber(const std::string& c);
public:
    static Stack<std::string> evaluate(int argc, char * argv[]);
};

#endif //PROJECT_2_PARSER_H
