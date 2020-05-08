#include<iostream>
using namespace std;
#ifndef StackArray_H_INCLUDED
#define StackArray_H_INCLUDED

template <class T>class Stack
{
    int listSize; //total number of elements in array
    T *arr;
    int capacity; //Maximum capacity
public:
    Stack();  //default constructor
    Stack(int s);  //make array of desired size
    ~Stack();  // destructor
    bool insertLast(T val); // insert at last empty index
    bool Push(T val); // insert at 0 index
    int Size(); // return capacity of array
    void print();
    T getElementAt(int );
    bool Pop(); // delete value at 0 index if available
    bool isEmpty(); //check the array either it is empty or not
    bool isFull();//check the array either it is full or not
    bool Clear(); //remove all elements from array
    bool Sort(); //sort array
    int Search(T key); //search at given index
    int searchRange(T key, int s,int l); // search b/w given range
    bool Palindrome(); // reverse the values in array
    int getElementCount(); // it returns last entered index
    bool BracesBalance(string);
};

#endif // StackArray_H_INCLUDED
