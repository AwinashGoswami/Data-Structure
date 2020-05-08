#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue()
{
    arr=NULL;
    rear=-1;
    front=-1;
    capacity=0;
    c=0;
}

template <class T>
Queue<T>::Queue(int s)
{
    capacity=s;
    arr=new T[capacity];
    rear=-1;
    front=-1;
    c=0;
}

template <class T>
Queue<T>::~Queue()
{
    delete []arr;
}

template <class T>
bool Queue<T>::EnQueue(T val)
{
    if(!this->isFull())
    {
        if(isEmpty())
        {
            rear=front=0;
            arr[rear]=val;
            rear++;
            c++;
            return 1;

        }
        else
        {
        arr[rear]=val;
        rear=(rear+1)%capacity;
        c++;
        return 1;
        }
    }
    else
        return 0;
}


template <class T>
bool Queue<T>::DeQueue()
{
    if(!this->isEmpty())
    {
        if(front!=capacity)
          {front=(front+1)%capacity; c--;}
        else
          {front=0;c--;}
    }
    else
        return 0;
}

template <class T>
void Queue<T>::print()
{
    int f=front;
    if(!this->isEmpty())
    {

        while(f!=rear )
        {
            cout<<arr[f]<<" ";
            f=(f+1)%capacity;
        }
        cout<<endl<<endl;
    }
    else
        cout<<"Sorry..!List is empty.\n";
}

template<class T>
bool Queue<T>:: isEmpty()
{
    if(rear==-1 || front==-1)
        return 1;
    else
        return 0;
}
template<class T>
bool Queue<T>::isFull()
{
    if(c==capacity-1)
        return 1;
    else
        return 0;
}

template class Queue <int>;

template class Queue <char>;

template class Queue<double>;


