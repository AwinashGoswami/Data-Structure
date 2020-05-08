#include <iostream>
#include "BSTNode.h"

using namespace std;

BSTNode::BSTNode()
{
    right=NULL;
    left=NULL;
}
void BSTNode::setRight(BSTNode* R)
{
    right=R;
}
void BSTNode::setLeft(BSTNode* l)
{
    left=l;
}
void BSTNode::setData(int d)
{
    data=d;
}
BSTNode* BSTNode::getRight()
{
    return right;
}
BSTNode* BSTNode::getLeft()
{
    return left;
}
int BSTNode::getData()
{
    return data;
}
