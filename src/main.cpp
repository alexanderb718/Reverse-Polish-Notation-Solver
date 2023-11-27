// main.cpp
// Alexander Bertholf
// Section 01
// Last Modified 11/5/2021

#include <iostream>
#include <string>
#include "stack.hpp"

int main(int argc, char *argv[]) {
    // Initialize stack
    Stack<std::string> stack;

    // Set capacity of stack to the number of arguments - 1
    stack.setCapacity(argc - 1);

    // Initialize i to 1 (ignores first argument because the first argument is not relevant)
    int i = 1;

    // Loop through arguments until it hits a nullptr
    while(*(argv + i) != nullptr) {
        // Push argument to stack
        stack.push(*(argv + i));

        // Increment i
        i++;
    }

    // Print result to console
    std::cout << "Result: " << stack.evaluate() << std::endl;

    // Exit program
    return EXIT_SUCCESS;
}
