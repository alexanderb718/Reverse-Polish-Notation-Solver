// Parser.cpp
// Alexander Bertholf
// Section 01
// Last Modified 11/8/2021

#include "parser.hpp"

/**
 * Gets the precedence of the given expression
 * @param str The given expression
 * @return The precedence of the given expression (add/subtract = 1, multiply/divide = 2, other = 0)
 */
int Parser::precedence(const std::string &str) {
    if(str == "+" || str == "-")
        return 1;
    else if (str == "*" || str == "/")
        return 2;
    else if (str == "^")
        return 3;
    else
        return 0;
}

/**
 * Checks if given string is a valid number (Check if every character is a number)
 * @param str Given string
 * @return True if all characters in the string are numbers\n False if there's a character that isn't a valid number
 */
bool Parser::isNumber(const std::string& str) {
    char* end = nullptr;
    double val = strtod(str.c_str(), &end);
    return end != str.c_str() && *end == '\0' && val != HUGE_VAL;
}

/**
 * Converts in-fix notation function to Reverse Polish Notation
 * I want that extra credit
 * Reference: https://www.tutorialspoint.com/Convert-Infix-to-Postfix-Expression
 * Modified to return a stack rather than a string
 * @param argc Count of arguments in argv
 * @param argv All arguments (Directly given from main function)
 * @return A stack containing reverse polish notation version of given function
 */
Stack<std::string> Parser::evaluate(int argc, char * argv[]) {
    // Will be used to store operations temporarily
    Stack<std::string> ops;

    // Final Reverse Polish Notation Stack
    Stack<std::string> rpn;

    // Set capacity of ops to 256, just a guess I made. I probably could improve this later
    ops.setCapacity(256);

    for(int i = 1; i < argc; i++) {
        // Set string exp to ith argument in argv
        std::string exp = argv[i];

        if(isNumber(exp)) {
            // If the expression is a number, push it to rpn stack
            rpn.push(exp);

        }
        else if(exp == "(") {
            // If the expression string is an open-parenthesis, push it to ops stack
            ops.push("(");
        }
        else if(exp == "^") {
            ops.push("^");
        }
        else if(exp == ")") {
            // If the expression string is a closed-parenthesis, push all values in ops to rpn stack
            while(ops.getSize() > 0 && ops.top() != "(") {
                rpn.push(ops.pop());
            }
            ops.pop(); // Pop ( from ops
        }
        else if(precedence(exp) > precedence(ops.top())) {
            // If the precedence of the current expression is greater than the precedence of the top of the ops stack, push to ops stack
            ops.push(exp);
        }
        else {
            // Otherwise, push all ops to rpn stack
            while(ops.getSize() > 0 && precedence(exp) <= precedence(ops.top())) {
                rpn.push(ops.pop());
            }

            // Push expression to ops
            ops.push(exp);
        }
    }

    // Push all ops to rpn stack
    while(ops.getSize() > 0) {
        rpn.push(ops.pop());
    }

    // Return Reverse Polish Notation Stack
    return rpn;
}