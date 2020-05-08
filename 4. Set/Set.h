#include<iostream>

using namespace std;

template <class T>
class Set{
protected:
    int listsize;
    int capacity;
    T * arr;
public:
    Set(int size);
    Set(const Set &arr);
    ~Set();
    void insertAtBegin(T el);
    bool insertAtEnd(T value);
    void insertAt(T value, int index);
    void deleteFromBegin();
    void deleteFromEnd();
    void deleteFromIndex(int index);
    void print();
    void Sort();
    int Search(T value);
    int getSize();
    void shiftLeft(int index);
    void shiftRight(int index);
    bool checkBounds(int index);
    bool isFull();
    bool isEmpty();
    int FirstIndexOf(T value);
    int LastIndexOf(T value);
    bool Contains(T value);
    void getbyIndex(int index);
    bool Remove(T value);
    bool add(T value);
    void Clear();
    bool addAll(Set<T> obj);
    void removeRange(int from, int end);
    void Intersection(Set<T> &obj);
    void Union(Set<T> &obj);
    void Difference(Set<T> &obj);


private:
T getValue(int index);
};
