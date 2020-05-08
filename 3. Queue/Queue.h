#include<iostream>
using namespace std;
#ifndef Queue_H_INCLUDED
#define Queue_H_INCLUDED

template <class T>
class Queue
{
    int c;
    int rear;
    int front;
    T *arr;
    int capacity;
public:
    Queue();
    Queue(int s);
    ~Queue();
    bool EnQueue(T val);
    void print();
    bool DeQueue();
    bool isEmpty();
    bool isFull();
    bool Clear();
    bool Sort();
    int Search(T key);
};

#endif // Queue_H_INCLUDED
