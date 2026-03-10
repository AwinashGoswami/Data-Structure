#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* arr;        // Dynamic array to store elements
    int top;         // Index of the top element
    int capacity;    // Maximum size of the stack

public:
    // Constructor and Destructor
    Stack(int size);
    ~Stack();

    // Basic Operations
    void push(int value);
    int pop();
    int peek();

    // Utility Functions
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};

#endif
