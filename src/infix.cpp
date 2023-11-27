// infix.cpp
// Alexander Bertholf
// Section 01
// Last Modified 11/5/21

#include <string>
#include "stack.hpp"
#include "parser.hpp"

int main(int argc, char * argv[]) {
    // Change function from infix notation to postfix notation
    Stack<std::string> rpn = Parser::evaluate(argc, argv);

    // Print stack to console
    rpn.print();

    return EXIT_SUCCESS;
}