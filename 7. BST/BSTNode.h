#ifndef BSTNODE_H_INCLUDED
#define BSTNODE_H_INCLUDED

class BSTNode
{
    int data;
    BSTNode *right;
    BSTNode *left;
public:
    BSTNode();
    void setRight(BSTNode*);
    void setLeft(BSTNode*);
    void setData(int);
    BSTNode* getRight();
    BSTNode* getLeft();
    int getData();
};


#endif // BSTNODE_H_INCLUDED
