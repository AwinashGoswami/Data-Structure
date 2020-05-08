#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

class Node
{
public:
    int data;
    Node *next;
    Node();
    void setdata(int);
};
class linklist
{
private:
    Node *Head;
public:
    linklist();
    bool insertAtBegin();
    bool insertAtEnd();
    bool insertAfter(int);
    bool insertBefore(int);
    bool deleteFromBegin();
    bool deleteFromEnd();
    bool deleteN(int);
    bool Delete();
    bool deleteList();
    Node search();
    bool update();
    void print();
};

#endif // LINKLIST_H_INCLUDED
