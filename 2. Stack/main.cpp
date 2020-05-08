#include <iostream>
#include "windows.h"
#include "Stack.h"
using namespace std;

int main()
{
    system("Color 74");
    int s;
    cout<<"Enter Size of Stack: ";
    cin>>s;
    while(s<=0)
    {

        cout<<"Wrong Entery.\n";
        cin>>s;
    }

    Stack<int> obj(s);
    int option;
    int value;
    int index;
    int key;
    do
    {
        system("CLS");
        cout<<"****************************\n";
        cout<<"------------Menu------------\n";
        cout<<"****************************\n";
        cout<<endl;
        cout<<
            "1.Push \n"
            "2.Pop \n"
            "3.Search Stack\n"
            "4.Clear Stack\n"
            "5.Print Stack \n"
            "6.Exit Program  \n"
            "\nEnter Option(Serial number): ";
        cin >> option;
        cout<<endl;
        switch(option)
        {
        case 1:
        {
            cout<<"Enter Value To Insert: ";
            cin>>value;
            obj.Push(value);
            break;
        }
        case 2:
        {
            obj.Pop();
            break;
        }

        case 3:
        {
            cout<<"Enter Value To Search: ";
            cin>>value;
            cout<<"At Index: " << obj.Search(value);
            break;
        }

        case 4:
        {
            obj.Clear();
            break;
        }

        case 5:
        {
            cout<<"Stack : "<<endl;
            obj.print();
            break;
        }
        case 6:
        {
            break;
        }
        default:
        {
            system("CLS");
            cout<<"Wrong Entery...!!\n";
        }
        }

    }

    while(option!=6);
    return 0;
}
