#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

// Node structure for both Stack and Queue
struct Node {
    int data;
    Node* next;

    // Constructor for easy node creation
    Node(int value) : data(value), next(nullptr) {}
};

#endif // NODE_H_INCLUDED
