#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack()
{
    arr=NULL;
    listSize=0;
    capacity=0;
}

template <class T>
Stack<T>::Stack(int s)
{
    capacity=s;
    arr=new T[capacity];
    listSize=0;
}

template <class T>
Stack<T>::~Stack()
{
    delete arr;
}

template <class T>
bool Stack<T>::Push(T val)
{
    T a,b;
    if(!this->isFull())
    {
        a=arr[0];
        b=arr[1];
        arr[0]=val;
        for(int i=1; i<=listSize; i++)
        {
            arr[i]=a;
            a=b;
            b=arr[i+1];
        }
        listSize++;
        return 1;
    }
    else
        return 0;

}

template <class T>
int Stack<T>::Size()
{
    return capacity;
}

template <class T>
bool Stack<T>::Pop()
{
    T *a;
    a=new T[capacity];
    if(!this->isEmpty())
    {

        for(int i=0; i<listSize-1; i++)
        {
            a[i]=arr[i+1];
        }
        delete arr;
        arr=a;
        listSize=listSize--;
        return 1;
    }
    else
        return 0;
}

template <class T>
void Stack<T>::print()
{
    if(!this->isEmpty())
    {
        for(int i=0; i<listSize; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
    }
    else
        cout<<"Sorry..!List is empty.\n";
}

template<class T>
T Stack<T>::getElementAt(int index)
{
    return arr[index];
}

template<class T>
bool Stack<T>:: isEmpty()
{
    if(listSize==0)
        return 1;
    else
        return 0;
}
template<class T>
bool Stack<T>::isFull()
{
    if(listSize==capacity)
        return 1;
    else
        return 0;
}

template<class T>
bool Stack<T>::Clear()
{
    T *a;
    if(listSize!=0)
    {
        a= new T[capacity];
        delete arr;
        arr=a;
        listSize=0;
        return 1;
    }
    else
        return 0;
}


template <class T>
int Stack<T>::Search(T key)
{
    for(int i=0; i<listSize; i++)
    {
        if(this->arr[i]==key)
            return i;
    }
    cout<<"no matches\n";
}

template<class T>
bool Stack<T>::Palindrome()
{
    int temp=listSize-1;
    for(int i=0; i<=listSize/2; i++)
    {
        if(this->arr[i]!=this->arr[temp])
            return 0;
        temp--;
    }
    return 1;
}
template<class T>
int Stack<T>::getElementCount()
{
    return listSize;
}
template<class T>
bool Stack<T>::BracesBalance(string s)
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='(')
            this->Push('(');
        else if(s[i]==')')
        {
            if(this->isEmpty())
            this->Pop();
        i++;}
    }
    if(this->isEmpty())
        return 1;
    else
        return 0;
}

template class Stack <int>;

template class Stack <char>;

template class Stack<double>;


