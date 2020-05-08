#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "Array.Lab.1.h"
using namespace std;

template <class T>
ArrayList<T>::ArrayList()
{
    arr=NULL;
    listSize=0;
    capacity=0;
}

template <class T>
ArrayList<T>::ArrayList(int s)
{
    if (s<0)
        cout<<"Error occured.\n";
        else{
    capacity=s;
    arr=new T[capacity];
    listSize=0;}
}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete arr;
}

template <class T>
bool ArrayList<T>::insertLast(T val)
{
    if(!this->isFull())
    {
        arr[listSize]=val;
        listSize++;
        return 1;
    }
    else
        return 0;
}

template <class T>
bool ArrayList<T>::insertFront(T val)
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
bool ArrayList<T>::insertAt(T val, int index)
{
    T a,b;
    if(!this->isFull() && index<listSize)
    {
        a=arr[index];
        b=arr[index+1];
        arr[index]=val;
        for(int i=index+1; i<listSize; i++)
        {
            arr[i]=a;
            a=b;
            b=arr[i+1];
        }
        return 1;
    }
    else
        return 0;

}

template <class T>
int ArrayList<T>::Size()
{
    return capacity;
}

template <class T>
bool ArrayList<T>::DeleteFront()
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
bool ArrayList<T>::deleteLast()
{
    T *a;
    a=new T[capacity];
    if(!this->isEmpty())
    {
        for(int i=0; i<listSize-1; i++)
        {
            a[i]=arr[i];
        }
        delete arr;
        arr=a;
        listSize=--listSize;
        return 1;
    }
    else
        return 0;

}

template <class T>
bool ArrayList<T>::DeleteFrom(int index)
{
    T *a;
    a=new T[capacity];
    if(!this->isEmpty())
    {
        for(int i=0; i<listSize; i++)
        {
            if(i==index || i>index)
            {
                a[i]=arr[i+1];
            }
            else
                a[i]=arr[i];
        }
        delete arr;
        arr=a;
        listSize=--listSize;
        return 1;
    }
    else
        return 0;
}

template <class T>
bool ArrayList<T>::DeleteRange(int s, int l)
{
    T *a;
    a=new T[capacity];
    if(!this->isEmpty())
    {
        int k=0;
        for(int i=0; i<s; i++)
        {
            a[i]=arr[i];
            k++;
        }
        int j=0;
        if(l<listSize)
        {
            for(int i=l; i<listSize; i++)
            {
                a[k]=arr[i];
                ++k;
            }
        }
        delete arr;
        arr=a;
        listSize=k;
    }
}

template <class T>
bool ArrayList<T>::expandBy(int Size)
{
    T *a;
    capacity=capacity+Size;
    a=new T[capacity];
    if(!this->isEmpty())
    {
        for(int i=0; i<listSize; i++)
        {
            a[i]=arr[i];
        }
        delete arr;
        arr=a;
        return 1;
    }
    else
        return 0;

}

template <class T>
bool ArrayList<T>::shrink()
{
    T *a;
    capacity=listSize;
    a=new T[capacity];
    if(!this->isEmpty())
    {
        for(int i=0; i<listSize; i++)
        {
            a[i]=arr[i];
        }
        delete arr;
        arr=a;
        return 1;
    }
    else
        return 0;
}

template <class T>
void ArrayList<T>::print()
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
T ArrayList<T>::getElementAt(int index)
{
    return arr[index];
}
template<class T>
T &ArrayList<T>::operator[](int& index)
{
    if(index<listSize && index>=0)
        return arr[index];
}

template<class T>
void ArrayList<T>::operator=(const ArrayList<T> &arr)
{
    this->Copy(arr);
}

template<class T>
void ArrayList<T>:: Copy(const ArrayList<T> &obj)
{
    if(obj.listSize!=0)
    {
        if(this->capacity > obj.listSize)
        {
            for(int i=0; i<obj.listSize; i++)
            {
                this->arr[i]=obj.arr[i];
            }
            this->listSize=obj.listSize;
        }
        else
        {
            for(int i=0; i<this->capacity; i++)
            {
                this->arr[i]=obj.arr[i];
                this->listSize++;
            }
        }
    }
}

template<class T>
bool ArrayList<T>:: isEmpty()
{
    if(listSize==0)
        return 1;
    else
        return 0;
}
template<class T>
bool ArrayList<T>::isFull()
{
    if(listSize==capacity)
        return 1;
    else
        return 0;
}

template<class T>
bool ArrayList<T>::Clear()
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

template<class T>
void ArrayList<T>::deleteElements(ArrayList<T> &obj)
{
    for(int i=0; i<listSize; i++)
    {
        for(int j=0; j<obj.listSize; j++)
        {
            if(arr[i]==obj.arr[j])
            {
                this->DeleteFrom(i);
                i--;
            }
        }
    }
}

template<class T>
bool ArrayList<T>:: Sort()
{
    if(!this->isEmpty())
    {
        for(int i=0; i<listSize; i++)
        {
            for (int j=0; j<listSize-1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    T temp;
                    temp=arr[j];
                    this->arr[j]=this->arr[j+1];
                    this->arr[j+1]=temp;
                }
            }
        }
        return 1;
    }
    else
        return 0;
}

template <class T>
int ArrayList<T>::Search(T key)
{
    for(int i=0; i<listSize; i++)
    {
        if(this->arr[i]==key)
            return i;
    }
    cout<<"no matches\n";
}

template <class T>
int ArrayList<T>:: searchRange(T key, int s,int l)
{
    if(s<listSize)
    {
        if(l<listSize)
        {
            for(int i=s; i<l; i++)
            {
                if(arr[i]==key)
                    return i;
            }
        }
        else
        {
            for(int i=s; i<listSize; i++)
            {
                if(arr[i]==key)
                {
                    cout<<"You Entered Higher limit greater than Size..\n"<<key
                        <<" is seached from index "<<s<<" to last one."<<"\n";
                    return i;
                }
            }
        }
        cout<<"No matches.\n";
    }
}

template<class T>
bool ArrayList<T>::Reverse()
{
    T *a;
    if(!this->isEmpty())
    {
        a=new T[capacity];
        int s=listSize;
        for(int i=0; i<listSize; i++)
        {
            a[i]=arr[--s];
        }
        delete arr;
        arr=a;
        return 1;
    }
    else
        return 0;
}

template<class T>
int ArrayList<T>::getElementCount()
{
    return listSize;
}

template <class T>
void ArrayList<T>::shuffle()
{
    srand(time(0));
    int a,b;
    T temp;
    for(int i=0; i<20; i++)
    {
        a= rand()% listSize,0;
        b=rand()%listSize,0;
        temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }

}

template class ArrayList <int>; // If we are using integer list. 'undefined reference' error without using this.

template class ArrayList <float>; // If we are using float list.'undefined reference' error without using this

template class ArrayList <double>; // If we are using double list.'undefined reference' error without using this

// Finally done.
