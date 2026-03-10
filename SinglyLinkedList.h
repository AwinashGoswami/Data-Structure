#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED

class SinglyLinkedList{

private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
public:
    SinglyLinkedList();

    void insertAtBegin(int value);
    void insertAtEnd(int value);
    void insertBefore(int value, int key);
    void insertAfter(int value, int key);

    void deleteFirst();
    void deleteLast();
    void deleteAfter(int key);
    void deleteBefore(int key);

    void traverse();
    //~SinglyLinkedList();
};


#endif // SINGLYLINKEDLIST_H_INCLUDED
