#include "LinkedListQueue.h"
#include <iostream>
using namespace std;

// Constructor
LinkedListQueue::LinkedListQueue() {
    front = nullptr;
    rear = nullptr;
    count = 0;
    cout << "Linked List Queue created" << endl;
}

// Destructor - Free all nodes
LinkedListQueue::~LinkedListQueue() {
    Node* current = front;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    cout << "Linked List Queue destroyed, all nodes freed" << endl;
}

// Enqueue operation - Add element to the rear
void LinkedListQueue::enqueue(int value) {
    Node* newNode = new Node(value);

    // If queue is empty, new node is both front and rear
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        // Add new node at the end and update rear
        rear->next = newNode;
        rear = newNode;
    }
    count++;
    cout << value << " enqueued to queue" << endl;
}

// Dequeue operation - Remove element from the front
int LinkedListQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Cannot dequeue from empty queue" << endl;
        return -1;
    }

    Node* temp = front;
    int value = temp->data;

    // Move front to next node
    front = front->next;

    // If front becomes nullptr, rear should also be nullptr
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    count--;

    return value;
}

// Peek operation - View front element without removing
int LinkedListQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return front->data;
}

// Check if queue is empty
bool LinkedListQueue::isEmpty() {
    return front == nullptr;
}

// Get current size
int LinkedListQueue::size() {
    return count;
}

// Display all elements
void LinkedListQueue::display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements (front to rear): ";
    Node* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Front: " << front->data;
    if (rear != nullptr) {
        cout << ", Rear: " << rear->data;
    }
    cout << ", Total elements: " << count << endl;
}
