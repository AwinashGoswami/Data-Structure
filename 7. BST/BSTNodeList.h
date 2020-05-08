#ifndef BSTNODELIST_H_INCLUDED
#define BSTNODELIST_H_INCLUDED
#include "BSTNode.h"
class BSTNodeList
{
    BSTNode *Root;
    int totalNodes;
public:
    BSTNodeList();
    void setRoot(BSTNode*);
    BSTNode* getRoot();
    BSTNode* getBSTNode(int);
    void insertData(int);
    bool deleteData(int);
    bool searchData(int);
    int NoOfNodes();
    int maxValue();
    int minValue();
    void printTree(BSTNode *);
    void ReadAndInsert(BSTNode *);
    BSTNode* GetParent(BSTNode * B, int key);
    void mirror(BSTNode *);
    int Height(BSTNode *);
    int maxdepth(BSTNode *);
    void PredecessorSuccessor(BSTNode*, BSTNode*& , BSTNode*& , int );

};

#endif // BSTNODELIST_H_INCLUDED
