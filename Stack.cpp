#include "Stack.h"
#include <iostream>
using namespace std;

// Constructor
Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
    cout << "Stack created with capacity: " << capacity << endl;
}

// Destructor
Stack::~Stack() {
    delete[] arr;
    cout << "Stack destroyed, memory freed" << endl;
}

// Push operation
void Stack::push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << value << endl;
        return;
    }
    arr[++top] = value;
    cout << value << " pushed to stack" << endl;
}

// Pop operation
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop from empty stack" << endl;
        return -1;  // Return -1 to indicate error
    }
    return arr[top--];
}

// Peek operation
int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return arr[top];
}

// Check if stack is empty
bool Stack::isEmpty() {
    return top == -1;
}

// Check if stack is full
bool Stack::isFull() {
    return top == capacity - 1;
}

// Get current size
int Stack::size() {
    return top + 1;
}

// Display all elements
void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
