#include <iostream>
#include <windows.h>
#include "BSTNodeList.h"
using namespace std;

int main()
{
    system("Color F4");
    cout<<"  Binary Search tree....!!\n";
    int d;
    int choice;
    BSTNodeList BST;
    Menu:
        {
            cout<<"\n\t__________________\n"
            "\t------ MENU ------\n"
            <<"\t------------------\n\n";
            cout<<"\t1. Insert Data.\n"
            <<"\t2.Delete data.\n"
            <<"\t3.Search Data.\n"
            <<"\t4.Number of nodes in tree.\n"
            <<"\t5.Maximum value in tree.\n"
            <<"\t6.Minimum value in tree.\n"
            <<"\t7.Print data of tree.\n"
            <<"\t8.Get Parent.\n"
            <<"\t9.Binary search tree to mirror.\n"
            <<"\t10.Max Height.\n"
            <<"\t11.Max Depth of tree.\n"
            <<"\t12.Predecessor and successor.\n"
            <<"Enter Option:";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"Enter Data: ";
                cin>>d;
                BST.insertData(d);
                goto Menu;
            case 2:
                cout<<"Enter Data: ";
                cin>>d;
                BST.deleteData(d);
                goto Menu;
            case 3:
                cout<<"Enter data: ";
                cin>>d;
                BST.searchData(d);
                goto Menu;
            case 4:
                cout<<"Total Nodes: "<< BST.NoOfNodes();
                goto Menu;
            case 5:
                cout<<"Max: "<<BST.maxValue();
                goto Menu;
            case 6:
                cout<<"Min: "<<BST.minValue();
                goto Menu;
            case 7:
                BST.printTree(BST.getRoot());
                goto Menu;
            case 8:
                int c;
                cout<<"Enter key: ";
                cin>>c;
                cout<<BST.GetParent(BST.getRoot(),c);
          case 9:
                BST.mirror(BST.getRoot());
                goto Menu;
          case 10:
                cout<<BST.Height(BST.getRoot());
                goto Menu;
          case 11:
                cout<<BST.maxdepth(BST.getRoot());
                goto Menu;
            case 12:
                BSTNode* pre;
                BSTNode* succs;
                int key;
                cout<<"Enter key: ";
                cin>>key;
                BST.PredecessorSuccessor(BST.getRoot(),pre ,succs,key);
                cout<<"Predecessor: "<<pre->getData();
                cout<<"\nSuccessor: "<<succs->getData();
                goto Menu;
            default:
                system("CLS");
                cout<<"You Entered Wrong option.\n";
                goto Menu;
            }
        }
}
