#include "Queue.h"
#include <iostream>
using namespace std;

// Constructor
Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
    cout << "Queue created with capacity: " << capacity << endl;
}

// Destructor
Queue::~Queue() {
    delete[] arr;
    cout << "Queue destroyed, memory freed" << endl;
}

// Enqueue operation - Add element to the rear
void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot enqueue " << value << endl;
        return;
    }

    // Circular increment of rear
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    count++;
    cout << value << " enqueued to queue" << endl;
}

// Dequeue operation - Remove element from the front
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Cannot dequeue from empty queue" << endl;
        return -1;
    }

    int value = arr[front];
    // Circular increment of front
    front = (front + 1) % capacity;
    count--;
    return value;
}

// Peek operation - View front element without removing
int Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return arr[front];
}

// Check if queue is empty
bool Queue::isEmpty() {
    return count == 0;
}

// Check if queue is full
bool Queue::isFull() {
    return count == capacity;
}

// Get current size
int Queue::size() {
    return count;
}

// Display all elements
void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements (front to rear): ";
    for (int i = 0; i < count; i++) {
        int index = (front + i) % capacity;
        cout << arr[index] << " ";
    }
    cout << endl;

    // Show front and rear positions for better understanding
    cout << "Front index: " << front << ", Rear index: " << rear << endl;
}
