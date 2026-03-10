#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

class DoublyLinkedList{
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };
    Node* head;
public:
    DoublyLinkedList();
    void insertAtBegin(int value);
    void insertAtEnd(int value);
    void insertBefore(int value, int key);
    void insertAfter(int value, int key);
    void traverse();
    //~DoublyLinkedList();
};


#endif // DOUBLYLINKEDLIST_H_INCLUDED
