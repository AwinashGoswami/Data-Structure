#ifndef CIRCULARLINKEDLIST_H_INCLUDED
#define CIRCULARLINKEDLIST_H_INCLUDED

class CircularLinkedList{
private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
public:
    CircularLinkedList();

    void insertAtBegin(int value);
    void insertAtEnd(int value);
    void insertBefore(int value, int key);
    void insertAfter(int value, int key);

    void deleteFirst();
    void deleteLast();
    void deleteAfter(int key);
    void deleteBefore(int key);

    void insertNode(int value);
    void traverse();
    //~CircularLinkedList();
};


#endif // CIRCULARLINKEDLIST_H_INCLUDED
