#ifndef LINKEDLISTQUEUE_H_INCLUDED
#define LINKEDLISTQUEUE_H_INCLUDED

#include "Node.h"

class LinkedListQueue {
private:
    Node* front;       // Pointer to the front node
    Node* rear;        // Pointer to the rear node
    int count;         // Number of elements

public:
    // Constructor and Destructor
    LinkedListQueue();
    ~LinkedListQueue();

    // Basic Operations
    void enqueue(int value);
    int dequeue();
    int peek();

    // Utility Functions
    bool isEmpty();
    int size();
    void display();
};



#endif // LINKEDLISTQUEUE_H_INCLUDED
