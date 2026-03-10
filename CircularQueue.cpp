#include "CircularQueue.h"
#include <iostream>
using namespace std;

// Constructor
CircularQueue::CircularQueue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
    cout << "Circular Queue created with capacity: " << capacity << endl;
}

// Destructor
CircularQueue::~CircularQueue() {
    delete[] arr;
    cout << "Circular Queue destroyed, memory freed" << endl;
}

// Enqueue operation - Add element to the rear
void CircularQueue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot enqueue " << value << " (Queue is full)" << endl;
        return;
    }

    // Circular increment of rear
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    count++;

    cout << value << " enqueued to queue" << endl;
    cout << "  Front index: " << front << ", Rear index: " << rear << endl;
}

// Dequeue operation - Remove element from the front
int CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Cannot dequeue from empty queue" << endl;
        return -1;
    }

    int value = arr[front];

    // Circular increment of front (logical removal)
    front = (front + 1) % capacity;
    count--;

    // Reset front and rear when queue becomes empty
    if (isEmpty()) {
        front = 0;
        rear = -1;
    }

    cout << value << " dequeued from queue" << endl;
    return value;
}

// Peek operation - View front element without removing
int CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return arr[front];
}

// View rear element without removing
int CircularQueue::rearElement() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return arr[rear];
}

// Check if queue is empty
bool CircularQueue::isEmpty() {
    return count == 0;
}

// Check if queue is full
bool CircularQueue::isFull() {
    return count == capacity;
}

// Get current size
int CircularQueue::size() {
    return count;
}

// Clear all elements
void CircularQueue::clear() {
    front = 0;
    rear = -1;
    count = 0;
    cout << "Queue cleared!" << endl;
}

// Display all elements with visual representation
void CircularQueue::display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "\n--- Queue Status ---" << endl;
    cout << "Elements (front to rear): ";

    // Display elements in order from front to rear
    for (int i = 0; i < count; i++) {
        int index = (front + i) % capacity;
        cout << arr[index] << " ";
    }
    cout << endl;

    // Display visual array representation
    cout << "\nArray view:" << endl;
    cout << "Index:  ";
    for (int i = 0; i < capacity; i++) {
        cout << " " << i << "  ";
    }
    cout << endl;

    cout << "Values: ";
    for (int i = 0; i < capacity; i++) {
        if (i == front && i == rear && count == 1) {
            cout << "[F/R]" << " ";
        } else if (i == front) {
            cout << "[F] " << " ";
        } else if (i == rear) {
            cout << "[R] " << " ";
        } else if ((front <= rear && i >= front && i <= rear) ||
                   (front > rear && (i >= front || i <= rear))) {
            printf("%-4d ", arr[i]);
        } else {
            cout << " -   ";
        }
    }
    cout << endl;

    // Show actual values in all positions
    cout << "Actual: ";
    for (int i = 0; i < capacity; i++) {
        if (i >= front && i <= rear && front <= rear) {
            printf("%-4d ", arr[i]);
        } else if (front > rear && (i >= front || i <= rear)) {
            printf("%-4d ", arr[i]);
        } else {
            cout << " -   ";
        }
    }
    cout << endl;

    cout << "\nStatistics:" << endl;
    cout << "  Front index: " << front << endl;
    cout << "  Rear index: " << rear << endl;
    cout << "  Current size: " << count << "/" << capacity << endl;
    cout << "  Is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    cout << "  Is full: " << (isFull() ? "Yes" : "No") << endl;
}
