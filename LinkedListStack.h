#ifndef LINKEDLISTSTACK_H_INCLUDED
#define LINKEDLISTSTACK_H_INCLUDED

#include "Node.h"

class LinkedListStack {
private:
    Node* top;        // Pointer to the top node
    int count;        // Number of elements

public:
    // Constructor and Destructor
    LinkedListStack();
    ~LinkedListStack();

    // Basic Operations
    void push(int value);
    int pop();
    int peek();

    // Utility Functions
    bool isEmpty();
    int size();
    void display();
};

#endif // LINKEDLISTSTACK_H_INCLUDED
