#include "SinglyLinkedList.h"
#include<iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList(){
    head = nullptr;
}

/***********************
        INSERTION
***********************/

// Insert at begin
void SinglyLinkedList::insertAtBegin(int value){
    Node* newNode = new Node();
    newNode->data = value;

    if(head==nullptr){
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

// Insert at end
void SinglyLinkedList::insertAtEnd(int value){
    Node* newNode = new Node();
    newNode->data = value;
    if (head == nullptr){
        head = newNode;
    }
    else {

        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Insert Before
void SinglyLinkedList::insertBefore(int value, int key){
    Node* curr = head;
    Node* prev = nullptr;

    if(head==nullptr){
        return;
    }

    if(head->data == key){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        return;
    }

    while(curr!=nullptr && curr->data!=key){
        prev = curr;
        curr = curr->next;
    }

    if(curr==nullptr){
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = curr;
    prev->next = newNode;
}

// Insert After
void SinglyLinkedList::insertAfter(int value, int key){
    Node* temp = head;

    while(temp!=nullptr && key!=temp->data){
        temp = temp->next;
    }

    if(temp==nullptr){
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

/***********************
        DELETION
***********************/

// Delete First Node
void SinglyLinkedList::deleteFirst(){

    if(head==nullptr)   //checks empty list
        return;

    Node* temp = head;
    head = temp->next;
    delete temp;
}

// Delete Last Node
void SinglyLinkedList::deleteLast(){

    // Case 1: Empty List
    if(head==nullptr)
        return;

    // Case 2: Single Node
    if(head->next==nullptr){
        delete(head);
        head = nullptr;
        return;
    }

    // Case 3: More than one Nodes
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Delete After
void SinglyLinkedList::deleteAfter(int key){

    // Case 1: Empty List
    if(head==nullptr)
        return;

    // Case 2: Single Node
    if(head->next==nullptr){
        delete(head);
        head = nullptr;
        return;
    }

     Node* temp = head;
     if (temp == nullptr || temp->next == nullptr)  // key not found or no node after
        return;


    // Case 3: More than one Nodes
    while(temp!=nullptr && temp->data!=key){
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Delete Before
void SinglyLinkedList::deleteBefore(int key) {
    // Case 1: Empty list or head contains key (nothing before head)
    if (head == nullptr || head->data == key)
        return;

    Node* prevPrev = nullptr;
    Node* prev = head;
    Node* curr = head->next;

    while (curr != nullptr && curr->data != key) {
        prevPrev = prev;
        prev = curr;
        curr = curr->next;
    }

    // Key not found or no node before key
    if (curr == nullptr)
        return;

    // Delete node before key
    if (prevPrev == nullptr) {
        // Node to delete is head
        head = curr;
    } else {
        prevPrev->next = curr;
    }

    delete prev;
}

/***********************
        RETRIEVE
***********************/

// Traverse
void SinglyLinkedList::traverse(){
    if(head==nullptr){
        cout<<"List is empty";
    }
    else {
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
}
