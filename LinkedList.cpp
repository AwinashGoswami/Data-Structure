#include "LinkedList.h"
#include<iostream>
using namespace std;

LinkedList::LinkedList(){
    head = nullptr;
}

void LinkedList::insertAtBegin(int value){
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


void LinkedList::insertAtEnd(int value){
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

void LinkedList::insertBefore(int value, int key){
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

void LinkedList::insertAfter(int value, int key){
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


void LinkedList::display(){
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
