#include <iostream>
#include <windows.h>
#include "Queue.h"
using namespace std;

int main()
{
    system("Color 74");
    int s;
    cout<<"Enter Size of Circular Queue: ";
    cin>>s;
    while(s<=0)
    {

        cout<<"Wrong Entery.\n";
        cin>>s;
    }

    Queue<int> obj(s);
    int option;
    int value;
    int index;
    int key;
    do
    {
        cout<<"****************************\n";
        cout<<"------------Menu------------\n";
        cout<<"****************************\n";
        cout<<endl;
        cout<<
            "1.En-queue \n"
            "2.De-Queue \n"
            "3.Check is Full\n"
            "4.Check is Empty\n"
            "5.Print Queue \n"
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
            obj.EnQueue(value);
            break;
        }
        case 2:
        {
            obj.DeQueue();
            break;
        }

        case 3:
        {
            cout<<"Check is Full: ";
            if(obj.isFull()==1)
                cout<<"Full\n";
            else
                cout<<"Not Full\n";
            break;
        }

        case 4:
        {
               cout<<"Check is Empty: ";
            if(obj.isEmpty()==1)
                cout<<"Empty\n";
            else
                cout<<"Not Empty\n";
            break;
        }

        case 5:
        {
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
