#include "CircularLinkedList.h"
#include<iostream>
using namespace std;

// Constructor
CircularLinkedList::CircularLinkedList(){
    head = nullptr;
}

/***********************
        INSERTION
***********************/

// Insert at begin
void CircularLinkedList::insertAtBegin(int value){
    Node* newNode = new Node();
    newNode->data = value;

    if(head==nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void CircularLinkedList::insertAtEnd(int value){
    Node* newNode = new Node();
    newNode->data = value;

    if(head==nullptr){
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
}

// Insert After
void CircularLinkedList::insertAfter(int value, int key){

    Node* newNode = new Node();
    newNode->data = value;

    if(head==nullptr){
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    do {
        if(temp->data==key)
            break;
        temp = temp->next;
    }
    while(temp!=head);

    // Key not found
    if(temp->data!=key){
        cout<<"Key not found";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert Before
void CircularLinkedList::insertBefore(int value, int key) {
    Node* newNode = new Node();
    newNode->data = value;

    // Case 1: Empty list
    if(head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;

    // Traverse to find the key
    do {
        if(curr->data == key)
            break;
        prev = curr;
        curr = curr->next;
    } while(curr != head);

    // Key not found
    if(curr->data != key){
        cout << "Key not found";
        return;
    }

    newNode->next = curr;

    if(prev == nullptr) {
        // Inserting before head
        // Find last node to maintain circular link
        Node* temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        head = newNode;
    } else {
        prev->next = newNode;
    }
}

/***********************
        DELETION
***********************/

// Delete first Node
void CircularLinkedList::deleteFirst(){

    if(head==nullptr){
        return;
    }

    // Case 1: Only one Node
    if(head->next==head){
        delete head;
        head = nullptr;
        return;
    }

    Node* nodeToDelete = head;
    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    temp->next = head->next;
    head = head->next;
    delete nodeToDelete;
}

// Delete Last Node
void CircularLinkedList::deleteLast(){

    if(head==nullptr){
        return;
    }

    // Case 1: Only one Node
    if(head->next==head){
        delete head;
        head = nullptr;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while(curr->next!=head){
        prev = curr;
        curr = curr->next;
    }

    prev->next = head;
    delete curr;
}

// Delete After
void CircularLinkedList::deleteAfter(int key){

    if(head == nullptr)
        return;

    // If only one node, nothing to delete after
    if(head->next == head)
        return;

    Node* curr = head;

    // Find key using do-while
    do {
        if(curr->data == key)
            break;
        curr = curr->next;
    } while(curr != head);

    // Key not found
    if(curr->data != key){
        cout << "Key not found";
        return;
    }

    Node* nodeToDelete = curr->next;

    // If deleting head, move head forward
    if(nodeToDelete == head){
        head = head->next;
    }

    curr->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Delete Before
void CircularLinkedList::deleteBefore(int key){

    if(head == nullptr)
        return;

    // If only one node, nothing to delete after
    if(head->next == head)
        return;

}

// Insert Node
void CircularLinkedList::insertNode(int value){
    Node* newNode = new Node();
    newNode->data = value;

    if(head == nullptr){
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

// Traverse
void CircularLinkedList::traverse(){
    Node* temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    while(temp!=head);
}


