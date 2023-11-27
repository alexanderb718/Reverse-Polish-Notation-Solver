// Stack.h
// Alexander Bertholf
// Section 01
// Last Modified 11/8/2021

#ifndef PROJECT_2_STACK2_H
#define PROJECT_2_STACK2_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

template<typename T>
class Stack {
    std::vector<T> pool;

    /**
     * Returns if the given operand is actually an operation
     * @param operand The operand
     * @return True if the value is an operation (+, -, *, /, ^) \n False if not one of the given operations (Number, etc)
     */
    bool isOperation(const std::string& operand) {
        return operand == "+" || operand == "-" || operand == "*" || operand == "/" || operand == "^";
    }
public:
    Stack() {
        // Allocate memory
        pool.reserve(100);
    }

    /**
     * Pushes a new element to the stack
     * @param el New element to add to stack
     */
    void push(const T& el) {
        pool.push_back(el);
    }

    /**
     * Removes element from stack and returns its value
     * @return Last element of the stack
     */
    T pop() {
        T el = pool.back();
        pool.pop_back();
        return el;
    }

    /**
     * Gets the last value in the stack
     * @return Last element of the stack
     */
    T top() {
        return pool.back();
    }

    /**
     * Resizes the capacity of the stack
     * @param capacity New capacity of the stack
     */
    void setCapacity(size_t capacity) {
        pool.resize(capacity);
    }

    /**
     * Gets the size of the stack
     * @return Size of the stack
     */
    size_t getSize() {
        return pool.size();
    }

    /**
     * Prints all values in the stack, from first element to last element
     */
    void print() {
        for(auto & it : pool) {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }

    /**
     * Evaluates function in Reverse Polish Notation style in Stack
     * @return The result of the function
     */
    double evaluate() {
        // Pop operation from stack
        std::string operation = pop();

        // If the top of the stack is an operation, set operand2 to evaluate, otherwise pop from the stack
        std::string operand2 = isOperation(top()) ? std::to_string(evaluate()) : pop();

        // If the top of the stack is an operation, set operand1 to evaluate, otherwise pop from the stack
        std::string operand1 = isOperation(top()) ? std::to_string(evaluate()) : pop();

        // Do the math
        switch(operation.at(0)) {
            case '+': return std::stod(operand1) + std::stod(operand2); // Add operands 1 and 2
            case '-': return std::stod(operand1) - std::stod(operand2); // Subtract operand2 from operand1
            case '*': return std::stod(operand1) * std::stod(operand2); // Multiply operands 1 and 2
            case '/': return std::stod(operand1) / std::stod(operand2); // Divide operand1 by operand2
            case '^': return pow(std::stod(operand1), std::stod(operand2)); // I know this isn't required, but I wanted to do it anyways
            default: throw std::runtime_error("Unsupported operation"); // This means that you put an operation that is not supported or an operation that does not exist
        }
    }
};

#endif //PROJECT_2_STACK2_H
