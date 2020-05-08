#include <iostream>
#include "BSTNodeList.h"

using namespace std;

BSTNodeList::BSTNodeList()
{
    Root=NULL;
    totalNodes=0;
}
void BSTNodeList::setRoot(BSTNode* R)
{
    Root=R;
}
BSTNode* BSTNodeList::getRoot()
{
    return Root;
}
BSTNode* BSTNodeList::getBSTNode(int data)
{
    BSTNode * newNode= new BSTNode;
    newNode->setData(data);
    return newNode;
}
void BSTNodeList::insertData(int d)
{
    totalNodes++;
    BSTNode * temp=getRoot();
    if(getRoot() == NULL)
        setRoot(getBSTNode(d));
    else
    {
        while(temp!=NULL)
        {
            if(temp->getData() >= d)
            {
                if(temp->getLeft()!=NULL)
                    temp=temp->getLeft();
                else
                {
                    temp->setLeft(getBSTNode(d));
                    break;
                }
            }
            else
            {
                if(temp->getRight()!=NULL)
                    temp=temp->getRight();
                else
                {
                    temp->setRight(getBSTNode(d));
                    break;
                }
            }
        }

    }

}
bool BSTNodeList::deleteData(int d)
{
    BSTNode * temp=getRoot();
    BSTNode * temp1=getRoot();
    if(getRoot() == NULL)
        cout<<"Tree is empty...!!\n";
    else
    {
        while(temp!=NULL)
        {
            if(temp->getData()==d)
            {
                cout<<"Deleted..!!\n";
                totalNodes=totalNodes-1;
                if(temp == getRoot())
                {
                    BSTNode *t1,*t2;
                    t1=temp->getRight();
                    t2=temp->getLeft();
                    setRoot(NULL);
                    totalNodes=0;
                    ReadAndInsert(t1);
                    ReadAndInsert(t2);
                }
                else
                {
                    if(temp1->getData() < temp->getData())
                    {
                        BSTNode *t=temp;
                        temp1->setRight(temp->getRight());
                        temp=temp->getLeft();
                        delete t;
                        ReadAndInsert(temp);
                    }
                    else
                    {
                        BSTNode *t=temp;
                        temp1->setLeft(temp->getLeft());
                        temp=temp->getRight();
                        delete t;
                        ReadAndInsert(temp);
                    }
                }
                break;
            }
            else if(temp->getData() > d)
            {
                if(temp->getLeft()!=NULL)
                {
                    temp1=temp;
                    temp=temp->getLeft();
                }
                else
                {
                    cout<<"Not Found.\n";
                    break;
                }
            }
            else
            {
                if(temp->getRight()!=NULL)
                {
                    temp1=temp;
                    temp=temp->getRight();
                }
                else
                {
                    cout<<"Not Found..\n";
                    break;
                }
            }
        }
    }
}
bool BSTNodeList::searchData(int d)
{
    BSTNode * temp=getRoot();
    if(getRoot() == NULL)
        cout<<"Tree is empty...!!\n";
    else
    {
        while(temp!=NULL)
        {
            if(temp->getData()==d)
            {
                cout<<"Found..\n";
                break;
            }
            else if(temp->getData() > d)
            {
                if(temp->getLeft()!=NULL)
                    temp=temp->getLeft();
                else
                {
                    cout<<"Not Found.\n";
                    break;
                }
            }
            else
            {
                if(temp->getRight()!=NULL)
                    temp=temp->getRight();
                else
                {
                    cout<<"Not Found..\n";
                    break;
                }
            }
        }
    }
}
int BSTNodeList::NoOfNodes()
{
    return totalNodes;
}
int BSTNodeList::maxValue()
{
    BSTNode * temp=getRoot();
    while(temp->getRight()!=NULL)
    {
        temp=temp->getRight();
    }
    return temp->getData();
}
int BSTNodeList::minValue()
{
    BSTNode * temp=getRoot();
    while(temp->getLeft()!=NULL)
    {
        temp=temp->getLeft();
    }
    return temp->getData();
}

void BSTNodeList::printTree(BSTNode * temp) //Preorder
{
    if(getRoot() == NULL)
        cout<<"Tree is empty..!!\n";
    else
    {
        if (temp)
        {
            cout << temp->getData() << " ";
            printTree(temp->getLeft());
            printTree(temp->getRight());
        }
    }
}

void BSTNodeList::ReadAndInsert(BSTNode *temp)
{
    if(temp)
    {
        insertData(temp->getData()) ;
        ReadAndInsert(temp->getLeft());
        ReadAndInsert(temp->getRight());
    }
}

BSTNode* BSTNodeList::GetParent(BSTNode * B, int key )
{
    if(B==NULL)
        return 0;
    if(B->getLeft() && B->getLeft()->getData() == key)
        return B;
    else if (B->getRight() && B->getRight()->getData() == key)
        return B;
    BSTNode * temp =GetParent(B->getLeft(),key);
    if(temp==NULL)
        return GetParent(B->getRight(),key);

    return temp;
}

void BSTNodeList::mirror(BSTNode *r)
{
    if(r==NULL)
        return;
    else
    {
        BSTNode * temp;
        mirror(r->getLeft());
        mirror(r->getRight());
        temp=r->getLeft();
        r->setLeft(r->getRight());
        r->setRight(temp);
    }
}
int BSTNodeList::Height(BSTNode * node)
{
    BSTNode* node1=node;
    BSTNode* node2=node;
    int temp;
    int height=0;
    if(node1==NULL)
    {
        return 0;
    }
    else if(node1->getLeft()!=NULL)
    {
        while(node1->getLeft())
        {
            height++;
            temp=height;
            node1=node1->getLeft();
        }
    }
    height=0;

    if(node2->getRight()!=NULL)
    {
        while(node2->getRight())
        {
            height++;
            node2=node2->getRight();

        }
    }


    if(temp>=height)
    {
        return temp;
    }
    else
        return height;

}


int BSTNodeList::maxdepth(BSTNode * n)
{
    if (n==NULL)
        return 0;
    else
    {
        int ldepth= maxdepth(n->getLeft());
        int rdepth= maxdepth(n->getRight());
        if(ldepth>rdepth)
            return (ldepth+1);
        else
            return rdepth+1;

    }
}

void BSTNodeList::PredecessorSuccessor(BSTNode* root, BSTNode*& pre, BSTNode*& suc, int key)
{

    if (root == NULL)  return ;

    if (root->getData() == key)
    {
        if (root->getLeft()!= NULL)
        {
            BSTNode* tmp = root->getLeft();
            while (tmp->getRight())
                tmp = tmp->getRight();
            pre = tmp ;
        }

        if (root->getRight()!= NULL)
        {
            BSTNode* tmp = root->getRight() ;
            while (tmp->getLeft())
                tmp = tmp->getLeft() ;
            suc = tmp ;
        }
        return ;
    }

    if (root->getData() > key)
    {
        suc = root ;
        PredecessorSuccessor(root->getLeft(), pre, suc, key) ;
    }
    else
        pre = root ;
    PredecessorSuccessor(root->getRight(), pre, suc, key) ;
}



