#include <iostream>
#include <windows.h>
#include "LinkList.h"
using namespace std;

int main()
{
    linklist l;
    int n,i;
    menu:
        {
            cout<<"\t********Menu********\n\n";
            cout<<"\tEnter 1 to add at Begin.\n";
            cout<<"\tEnter 2 to add at Last.\n";
            cout<<"\tEnter 3 to add Before.\n";
            cout<<"\tEnter 4 to add After.\n";
            cout<<"\tEnter 5 to Delete from Begin.\n";
            cout<<"\tEnter 6 to Delete from End.\n";
            cout<<"\tEnter 7 to Delete any.\n";
            cout<<"\tEnter 8 to Delete Max.\n";
            cout<<"\tEnter 9 to Delete list.\n";
            cout<<"\tEnter 10 to Print.\n";
            cout<<"\tEnter 0 to exit.\n";
            cout<<"\tEnter any other value to go to main menu.\n";
            cin>>n;
            switch(n)
            {
            case 1:
                l.insertAtBegin();
                goto menu;
                break;
            case 2:
                l.insertAtEnd();
                goto menu;
                break;
            case 3:
                cout<<"Enter value to enter Node Before: ";
                cin>>i;
                l.insertBefore(i);
                goto menu;
                break;
            case 4:
                cout<<"Enter value to enter Node after: ";
                cin>>i;
                l.insertAfter(i);
                goto menu;
                break;
            case 5:
                l.deleteFromBegin();
                goto menu;
                break;
            case 6:
                l.deleteFromEnd();
                goto menu;
                break;
            case 7:
                cout<<"Enter data to delete that index: ";
                cin>>i;
                l.deleteN(i);
                goto menu;
                break;
            case 8:
                l.Delete();
                goto menu;
                break;
            case 9:
                l.deleteList();
                goto menu;
                break;
            case 10:
                l.print();
                goto menu;
                break;
            case 0:
                return 0;
            default:
                system("CLS");
                goto menu;

            }

        }
}
