#ifndef CIRCULARLINKEDLISTQUEUE_H_INCLUDED
#define CIRCULARLINKEDLISTQUEUE_H_INCLUDED

#include "Node.h"

class CircularLinkedListQueue {
private:
    Node* rear;         // Pointer to the rear node (last node)
    int count;          // Number of elements

public:
    // Constructor and Destructor
    CircularLinkedListQueue();
    ~CircularLinkedListQueue();

    // Basic Operations
    void enqueue(int value);  // Add element to rear
    int dequeue();            // Remove element from front
    int peek();               // View front element
    int rearElement();        // View rear element

    // Utility Functions
    bool isEmpty();
    int size();
    void display();
    void clear();

    // Additional Operations
    void rotate();            // Move front to rear (rotation)
};


#endif // CIRCULARLINKEDLISTQUEUE_H_INCLUDED
