#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
class LinkedList{

private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
public:
    LinkedList();
    void insertAtBegin(int value);
    void insertAtEnd(int value);
    void insertBefore(int value, int key);
    void insertAfter(int value, int key);
    //void traverseCircularLinkedList();
    void display();
    //~LinkedList();
};


#endif // LINKEDLIST_H_INCLUDED
