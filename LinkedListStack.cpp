#include "LinkedListStack.h"
#include <iostream>
using namespace std;

// Constructor
LinkedListStack::LinkedListStack() {
    top = nullptr;
    count = 0;
    cout << "Linked List Stack created" << endl;
}

// Destructor - Free all nodes
LinkedListStack::~LinkedListStack() {
    Node* current = top;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    cout << "Linked List Stack destroyed, all nodes freed" << endl;
}

// Push operation - Add element to the top
void LinkedListStack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    count++;
    cout << value << " pushed to stack" << endl;
}

// Pop operation - Remove element from the top
int LinkedListStack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop from empty stack" << endl;
        return -1;
    }

    Node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    count--;

    return value;
}

// Peek operation - View top element without removing
int LinkedListStack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return top->data;
}

// Check if stack is empty
bool LinkedListStack::isEmpty() {
    return top == nullptr;
}

// Get current size
int LinkedListStack::size() {
    return count;
}

// Display all elements
void LinkedListStack::display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Stack elements (top to bottom): ";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    cout << "Total elements: " << count << endl;
}
