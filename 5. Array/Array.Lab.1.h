#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

template <class T>class ArrayList
{
    int listSize; //total number of elements in array
    T *arr;
    int capacity; //Maximum capacity
public:
    ArrayList();  //default constructor
    ArrayList(int s);  //make array of desired size
    ~ArrayList();  // destructor
    bool insertLast(T val); // insert at last empty index
    bool insertFront(T val); // insert at 0 index
    bool insertAt(T val, int index); // insert at desired index
    int Size(); // return capacity of array
    bool DeleteFront(); // delete value at 0 index if available
    bool deleteLast(); // delete value at last filled index
    bool DeleteFrom(int index); // delete at desired index
    bool DeleteRange(int s, int l); // delete elements b/w given range
    bool expandBy(int Size); // expand size of array if required
    bool shrink(); // shrink array
    void print(); // display data in array
    T getElementAt(int index); // return element at given index
    T &operator[](int &index); // subscript overloading operator
    void operator=(const ArrayList<T> &arr); //compare by overloading operator
    void Copy(const ArrayList<T> &obj); // copy from one array to another
    bool isEmpty(); //check the array either it is empty or not
    bool isFull();//check the array either it is full or not
    bool Clear(); //remove all elements from array
    void deleteElements(ArrayList<T> &obj); // delete elements
    bool Sort(); //sort array
    int Search(T key); //search at given index
    int searchRange(T key, int s,int l); // search b/w given range
    bool Reverse(); // reverse the values in array
    void shuffle(); // shuffle all value in array
    int getElementCount(); // it returns last entered index
};

#endif // ARRAYLIST_H_INCLUDED
