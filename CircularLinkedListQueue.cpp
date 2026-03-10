#include "CircularLinkedListQueue.h"
#include <iostream>
using namespace std;

// Constructor
CircularLinkedListQueue::CircularLinkedListQueue() {
    rear = nullptr;
    count = 0;
    cout << "Circular Linked List Queue created" << endl;
}

// Destructor - Free all nodes
CircularLinkedListQueue::~CircularLinkedListQueue() {
    clear();
    cout << "Circular Linked List Queue destroyed" << endl;
}

// Enqueue operation - Add element to the rear
void CircularLinkedListQueue::enqueue(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        // First node points to itself
        newNode->next = newNode;
        rear = newNode;
    } else {
        // New node points to front (rear->next)
        newNode->next = rear->next;
        // Rear points to new node
        rear->next = newNode;
        // Update rear to new node
        rear = newNode;
    }

    count++;
    cout << value << " enqueued to queue" << endl;
    cout << "  Rear: " << rear->data << ", Front: " << rear->next->data << endl;
}

// Dequeue operation - Remove element from the front
int CircularLinkedListQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Cannot dequeue from empty queue" << endl;
        return -1;
    }

    Node* front = rear->next;  // Front is next of rear
    int value = front->data;

    if (rear == front) {
        // Only one node in the queue
        rear = nullptr;
    } else {
        // More than one node
        rear->next = front->next;
    }

    delete front;
    count--;

    cout << value << " dequeued from queue" << endl;
    return value;
}

// Peek operation - View front element without removing
int CircularLinkedListQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return rear->next->data;  // Front is next of rear
}

// View rear element without removing
int CircularLinkedListQueue::rearElement() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return rear->data;
}

// Check if queue is empty
bool CircularLinkedListQueue::isEmpty() {
    return rear == nullptr;
}

// Get current size
int CircularLinkedListQueue::size() {
    return count;
}

// Clear all elements
void CircularLinkedListQueue::clear() {
    if (isEmpty()) {
        return;
    }

    Node* current = rear->next;  // Start from front
    Node* nextNode;

    // Break the circular link to avoid infinite loop
    rear->next = nullptr;
    rear = nullptr;

    // Delete all nodes
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    count = 0;
    cout << "Queue cleared!" << endl;
}

// Rotate - Move front element to rear
void CircularLinkedListQueue::rotate() {
    if (isEmpty() || count == 1) {
        cout << "Cannot rotate (queue empty or has only one element)" << endl;
        return;
    }

    // In circular linked list, rotating is just moving rear to next node
    rear = rear->next;
    cout << "Queue rotated (front moved to rear)" << endl;
}

// Display all elements with visual representation
void CircularLinkedListQueue::display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "\n--- Circular Queue Status ---" << endl;
    cout << "Elements (front to rear): ";

    Node* current = rear->next;  // Start from front
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != rear->next);  // Until we come back to front

    cout << endl;

    // Visual representation of the circular linked list
    cout << "\nCircular Linked List Structure:" << endl;

    current = rear->next;  // Start from front
    int nodeNum = 0;

    do {
        cout << "Node" << nodeNum << " [ data: " << current->data;
        cout << ", next points to: ";

        if (current->next == rear->next) {
            cout << "FRONT (Node0)";
        } else if (current == rear) {
            cout << "REAR (this node)";
        } else {
            cout << "Node" << (nodeNum + 1);
        }

        cout << " ]" << endl;

        current = current->next;
        nodeNum++;
    } while (current != rear->next);

    cout << "\nQueue Information:" << endl;
    cout << "  Front element: " << rear->next->data << endl;
    cout << "  Rear element: " << rear->data << endl;
    cout << "  Current size: " << count << endl;
    cout << "  Is empty: " << (isEmpty() ? "Yes" : "No") << endl;

    // Show the circular nature
    cout << "\nCircular Connection: ";
    cout << "Front → ... → Rear → Front (circular)" << endl;
}
