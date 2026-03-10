#include "DoublyLinkedList.h"
#include<iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList(){
    head = nullptr;
}

// Insert at end
void DoublyLinkedList::insertAtEnd(int value){

    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if(head==nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at begin
void DoublyLinkedList::insertAtBegin(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(head==nullptr){
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert After
void DoublyLinkedList::insertAfter(int value, int key)
{
    if (head == nullptr)
        return;

    Node* temp = head;

    // Find key
    while (temp != nullptr && temp->data != key)
    {
        temp = temp->next;
    }

    // If key not found
    if (temp == nullptr)
    {
        cout << "Key not found";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Insert Before
void DoublyLinkedList::insertBefore(int value, int key)
{
    if (head == nullptr)
        return;

    Node* curr = head;

    // Step 1: Find key
    while (curr != nullptr && curr->data != key)
    {
        curr = curr->next;
    }

    // Step 2: If key not found
    if (curr== nullptr)
    {
        cout << "Key not found";
        return;
    }

    // Step 3: Create new Node
    Node* newNode = new Node();
    newNode->data = value;

    // Step 4: Adjust pointers
    newNode->next = curr;
    newNode->prev = curr->prev;

    if (curr->prev!= nullptr)
        curr->prev->next = newNode;
    else
        head = newNode;

    curr->prev = newNode;
}
void DoublyLinkedList::traverse(){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
