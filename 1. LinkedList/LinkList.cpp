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
    n->setdata(d);
    n->next=Head;
    Head=n;
}
bool linklist::insertAtEnd()
{
    int d;
    Node *n=new Node;
    cout<<"Enter Data: ";
    cin>>d;
    n->data=d;
    if(Head==NULL)
        Head=n;
    else
    {
        Node *temp=Head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=n;
    }

}
bool linklist::insertAfter(int value)
{
    Node *temp=Head;
    while(temp!=NULL)
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
            return 1;
        }
        temp=temp->next;
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
    if(Head!=NULL)
    {
        Node *temp=Head;
        Head=Head->next;
        delete temp;
        return 1;
    }
    return 0;
}
bool linklist::deleteFromEnd()
{
    Node *temp=Head;
    Node *prev;
    if(Head!=NULL)
    {
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        delete temp;
        return 1;
    }
    return 0;
}
bool linklist::deleteN(int value)
{
    Node *temp=Head;
    Node *prev=Head;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            if(temp==Head)
                deleteFromBegin();
            else
            {
                prev=temp->next;
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
    return 0;

}
bool linklist::Delete()
{
    if(Head!=NULL)
    {
        Node *temp=Head;
        int max=temp->data;
        while(temp!=NULL)
        {
            if(max<temp->data)
                max=temp->data;
            temp=temp->next;
        }
        return deleteN(max);
    }
    return 0;
}
bool linklist::deleteList()
{
    Node *temp;
    while(Head!=NULL)
    {
        temp=Head;
        Head=Head->next;
        delete temp;
    }
}
void linklist::print()
{
    if(Head!=NULL)
    {
    Node *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    }
    else
        cout<<"List is empty.\n";
}
