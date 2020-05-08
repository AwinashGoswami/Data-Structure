#include "Set.h"

template <class T>
Set<T>::Set(int size)
{
    listsize=0;
    capacity=size;
    arr = new T[size];
}

template <class T>
Set<T>::~Set()
{
    delete arr;
}
template <class T>
Set<T>::Set(const Set<T> &arr1)
{
    this->listsize = arr1.listsize;
    this->capacity = arr1.capacity;
    this->arr = arr1.arr;
    this->arr= new T[capacity];
    for(int i =0; i<listsize; i++)
    {
        this->arr[i]=arr[i];
    }

}

template <class T>
void Set<T>::shiftRight(int index=0)
{
    for(int i=listsize; i>index; i--)
    {
        arr[i]=arr[i-1];
    }
}
template <class T>
void Set<T>::shiftLeft(int index=0)
{
    for(int i=index; i<listsize; i++)
    {
        arr[i]=arr[i+1];
    }
}
template <class T>
void Set<T>::insertAtBegin(T value)
{
    if(Search(value)==-1)
    {
        shiftRight(0);
        arr[0]=value;
        listsize++;
    }
    else
        cout<<"";
}

template <class T>
bool Set<T>::insertAtEnd(T value)
{
    if(Search(value)==-1)
    {
        if(isFull())
        {
           return false;
        }
        else
        {
            arr[listsize]=value;
            listsize++;
            return true;
        }

    }
    else
        cout<<"";
}


template <class T>
bool Set<T>::isFull()
{
    if(listsize==capacity)
    {
        return true;
    }
    else
        return false;
}

template <class T>
bool Set<T>::isEmpty()
{
    if(listsize==0)
    {
        return true;
    }
    else
        return false;
}

template <class T>
bool Set<T>::add(T value)
{
    return this->insertAtEnd(value);
}

template <class T>
void Set<T>::deleteFromIndex(int index)
{
    shiftLeft(index);
    listsize--;
}

template <class T>
bool Set<T>::checkBounds(int index)
{

    if(index<0 || index>listsize)
    {
        return true;
    }
    else
        return false;

}


template <class T>
void Set<T>::print()
{
    if(isEmpty())
        cout<<"SET is Empty.\n";
    {
        for(int i=0; i<listsize; i++)
            cout<<arr[i]<<"  ";
    }
}

template <class T>
void Set<T>::Sort()
{
    T temp;
    for(int i=0; i<this->listsize; i++)
    {
        for(int j=0; j<this->listsize; j++)
        {
            if(this->arr[j]>this->arr[j+1])
            {
                temp=this->arr[j];
                this->arr[j]=this->arr[j+1];
                this->arr[j+1]=temp;
            }
        }
    }
}


template <class T>
int Set<T>::Search(T value)
{
    for(int i=0; i<listsize; i++)
    {
        if(arr[i]==value)
        {
            return i;
            break;
        }
    }
    return -1;

}

template <class T>
void Set<T>::Clear()
{
    for(int i=0; i<listsize; i++)
    {
        arr[i]=-1;
    }
    listsize=0;
}

template <class T>
void Set<T>::Intersection(Set<T> &obj)
{
    for(int i =0; i<listsize; i++)
    {
        if(obj.Search(arr[i])>-1)
        {
            {
                cout<<getValue(i)<<" ";
            }
        }
    }

}
template <class T>
T Set<T>::getValue(int index)
{
    return arr[index];
}

template <class T>
void Set<T>::Union(Set<T> &obj)
{

    Set<T> temp(this->capacity+obj.capacity);
    for(int i=0; i<listsize; i++)
    {
        temp.arr[i]=arr[i];
        temp.listsize++;
    }
    for(int i =0; i<obj.listsize; i++)
    {
        if(Search(obj.arr[i])==-1)
        {
            temp.insertAtEnd(obj.arr[i]);
        }

        else
            cout<<"";
    }
    temp.print();
    cout<<endl;

}


template <class T>
void Set<T>::Difference(Set<T> &obj)
{
    Set<T> temp(this->capacity);
    for(int i=0; i<listsize; i++)
    {
        temp.arr[i]=arr[i];
        temp.listsize++;
    }
    T buffer;
    for(int i = 0; i < obj.listsize; i++)
    {
        buffer=temp.Search(obj.arr[i]);
        if(buffer!=-1)
        {
            temp.deleteFromIndex(buffer);
        }

    }
    temp.print();
}

template class Set<int>;
template class Set<float>;
template class Set<double>;
