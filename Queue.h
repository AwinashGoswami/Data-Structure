#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

class Queue {
private:
    int* arr;        // Dynamic array to store elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int capacity;    // Maximum size of the queue
    int count;       // Current number of elements

public:
    // Constructor and Destructor
    Queue(int size);
    ~Queue();

    // Basic Operations
    void enqueue(int value);  // Add element to rear
    int dequeue();            // Remove element from front
    int peek();               // View front element

    // Utility Functions
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};


#endif // QUEUE_H_INCLUDED
