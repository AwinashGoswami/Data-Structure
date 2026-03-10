#ifndef CIRCULARQUEUE_H_INCLUDED
#define CIRCULARQUEUE_H_INCLUDED

class CircularQueue {
private:
    int* arr;        // Dynamic array to store elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int capacity;    // Maximum size of the queue
    int count;       // Current number of elements

public:
    // Constructor and Destructor
    CircularQueue(int size);
    ~CircularQueue();

    // Basic Operations
    void enqueue(int value);  // Add element to rear
    int dequeue();            // Remove element from front
    int peek();               // View front element
    int rearElement();        // View rear element

    // Utility Functions
    bool isEmpty();
    bool isFull();
    int size();
    void display();
    void clear();             // Remove all elements
};

#endif // CIRCULARQUEUE_H_INCLUDED
