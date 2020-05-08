#include<iostream>
#include "LinkList.h"
using namespace std;

Node::Node()
{
    next=NULL;
}
void Node::setdata(int d)
{
    data=d;
}
linklist::linklist()
{
    Head=NULL;
}
bool linklist::insertAtBegin()
{
    int d;
    Node *n=new Node;
    cout<<"Enter Data: ";
    cin>>d;
    n->data=d;
    if(Head==NULL)
    {
        Head=n;
        Head->next=Head;
    }
    else
    {
        Node *temp=Head;
        while(temp->next!=Head)
            temp=temp->next;
        temp->next=n;
        n->next=Head;
        Head=n;
    }

}
bool linklist::insertAtEnd()
{
    int d;
    Node *n=new Node;
    cout<<"Enter Data: ";
    cin>>d;
    n->data=d;
    if(Head==NULL)
        {
            Head=n;
            Head->next=Head;
        }
    else
    {
        Node *temp=Head;
        while(temp->next!=Head)
            temp=temp->next;
        temp->next=n;
        n->next=Head;
    }

}
bool linklist::insertAfter(int value)
{
    Node *temp=Head;
    while(temp->next!=Head)
    {
        if(temp->data==value)
        {
            int d;
            Node *n=new Node;
            cout<<"Enter Data: ";
            cin>>d;
            n->data=d;
            n->next=temp->next;
            temp->next=n;
            if(n->next==NULL)
                n=Head;
            return 1;
        }
        temp=temp->next;
    }
    if(temp->data==value)
    {
            int d;
            Node *n=new Node;
            cout<<"Enter Data: ";
            cin>>d;
            n->data=d;
            n->next=temp->next;
            temp->next=n;
            return 1;
    }
    return 0;

}
bool linklist::insertBefore(int value)
{
    Node *temp=Head;
    Node *prev=Head;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            if(temp==Head)
                insertAtBegin();
            else
            {
                int d;
                Node *n=new Node;
                cout<<"Enter Data: ";
                cin>>d;
                n->data=d;
                n->next=temp;
                prev->next=n;
            }
            return 1;
        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    return 0;
}
bool linklist::deleteFromBegin()
{
    Node *A=Head;
    Node *temp=Head;
    if(Head!=NULL)
    {
        if(Head->next==Head)
        {
            Head=NULL;
            return 1;
        }
        Head=Head->next;
        while(temp->next!=A)
        {
            temp=temp->next;
        }
        temp->next=Head;
        delete A;
        return 1;
    }
    return 0;
}
bool linklist::deleteFromEnd()
{
    Node *temp=Head;
    Node *prev=Head;
    if(Head!=NULL)
    {
        if(Head->next==Head)
        {
            Head=NULL;
            return 1;
        }
        while(temp->next!=Head)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=Head;
        delete temp;
        return 1;
    }
    return 0;
}
bool linklist::deleteN(int value)
{
    Node *temp=Head;
    Node *prev=Head;
    while(Head!=NULL)
    {
    while(temp->next!=Head)
    {
        if(temp->data==value)
        {
            if(temp==Head)
                deleteFromBegin();
            else
            {
                prev->next=temp->next;
                delete temp;
            }
            return 1;
        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    if(temp->data==value)
    {
        if(temp->next==temp)
        {
            delete temp;
            Head=NULL;
            return 1;
        }
        prev->next=temp->next;
        delete temp;
        return 1;
    }
    }
    return 0;

}

bool linklist::deleteList()
{
    while(Head!=NULL)
        deleteFromBegin();
}
void linklist::print()
{
    if(Head!=NULL)
    {
    Node *temp=Head;
    while(temp->next!=Head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
    }
    else
        cout<<"List is empty.\n";
}
