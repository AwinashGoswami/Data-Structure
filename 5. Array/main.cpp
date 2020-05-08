#include <iostream>
#include <windows.h>
#include "Array.Lab.1.h"
using namespace std;

int main()
{
    system("color 1E");  // set console color
    ArrayList<int> A(10); //Array List of capacity 10
    /*
    catch(...)
    {
        cout<<"Error occured.\n";
    }*/
    cout<<"Array List: ";
    A.print();
    for(int i=2; i<6; i++)
    {
        A.insertFront(i); //inserting 5 values at front
    }
    for(int i=1; i<5; i++)
    {
        A.insertLast(i); // inserting 4 values at last
    }
    A.expandBy(6); // increasing size by 6

    A.insertAt(30,2); // inserting 30 at index 2
    A.insertAt(12,4); // inserting 12 at index 4
    A.insertAt(22,3);// inserting 12 at index 3
    A.DeleteFrom(3); // deleting value at index 3
    A.DeleteFront(); // deleting front value
    cout<<"\nArray List, After insertion: ";
    A.print();
    cout<<endl;
    A.Sort(); //sorting list
    cout<<"After Sorting: ";
    A.print();
    cout<<endl;
    A.Reverse(); //reversing list
    cout<<"After reversing: ";
    A.print();
    cout<<endl;
    cout<<"After shuffling: ";
    A.shuffle();
    A.print();
    cout<<endl;
    int c=1;
    cout<<"Searched "<<c<<"at index : ";
    cout<<A.Search(c); // searching value of c in list
    cout<<endl;
    cout<<"size= "<<A.Size()<<endl;
    cout<<"List capacity= "<<A.getElementCount();
    ArrayList<int> B(10);
    cout<<endl;
    B.Copy(A);
    cout<<"\nAfter copying to another Array List.\n\n";
    cout<<"Another object: ";
    B.print();
    for(int i=0; i<3; i++)
        B.DeleteFront();
    for(int i=0; i<2; i++)
        B.DeleteRange(3,5); //deleting values b/w index 3 and 6
    cout<<"Deleting elements in List: ";
    A.print();
    cout<<"Which are present in List. :";
    B.print();
    cout<<"After Deleting.:";
    A.deleteElements(B);
    A.print();
    cout<<"After writing value in Array list through subscripting overloading options.\n";
    int k=1;
    A[k]=300; //writing value in list through array subscripting overloading operator
    cout<<"\nList.: ";
    A.print();
    return 0;
}
