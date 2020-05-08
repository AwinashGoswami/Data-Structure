#include <iostream>
#include <windows.h>
#include "Set.h"

using namespace std;
int main()
{
    system("color 74");
int s;
cout<<"Enter Size of Set: "<<endl;
cin>>s;
int choice;
char set;
int value;
int i1;
int i2;
int key;


Set<int> setOne(s);
Set<int> setTwo(10);
setTwo.insertAtEnd(17);
setTwo.insertAtEnd(22);


do{
      cout<<"\n******************************\n";
      cout<<"-------------MENU-------------\n";
      cout<<"******************************\n\n"
      "1.Add element \n"
      "2.Delete Element\n"
      "3.Take Union with Set={17,22,26} \n"
      "4.Take Intersection with Set={17,22,26}\n"
      "5.Take Difference with Set={17,22,26}\n"
      "6.Search element in Set.\n"
      "7.Check is Empty\n"
      "8.Check is Full\n"
      "9.Sort\n"
      "10.Print the Set\n"
      "11.Clear Set(delete all).\n"
      "12.Exit Program \n"

      "\nEnter choice (Serial Number): ";
      cin >> choice;

    switch(choice){

case 1:
    {
    cout<<"Enter Value: ";
    cin>>value;
    setOne.insertAtBegin(value);
    break;
    }
case 2:
    {
    cout<<"Enter Index To Delete At " <<endl;
    cin>>i1;
    setOne.deleteFromIndex(i1);
    break;
    }

case 3:
    {
    cout<<"Taking Union......\n";
    setOne.Union(setTwo);
    break;
    }

case 4:
    {
    cout<<"Taking Intersecting....."<<endl;
    setOne.Intersection(setTwo);
    break;
    }

case 5:
    {
    cout<<"Taking Difference...."<<endl;
    setOne.Difference(setTwo);
    break;
    }


case 6:
    {
    cout<<"Enter Value To Search: ";
    cin>>value;
    setOne.Search(value);
    break;
    }

case 7:
    {
    if(setOne.isEmpty()){
        cout<<"Set is Empty."<<endl;
    }
    else
        cout<<"Set is not Empty."<<endl;
    break;
    }

case 8:
    {
    if(setOne.isFull()){
        cout<<"Set is Full."<<endl;
    }
    else
        cout<<"Set is not Full."<<endl;
    break;
    }

case 9:
    {
    setOne.Sort();
    break;
    }

case 10:
    {
    setOne.print();
    break;
    }
case 11:
    {
        setOne.Clear();
        break;
    }
case 12:
    {
        break;
    }
default:
    {
     cout<<"Wrong Entery...!!"<<endl;
    }
}
}

while(choice!=12);
    return 0;
}


