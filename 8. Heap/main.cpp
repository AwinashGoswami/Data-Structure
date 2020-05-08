#include <iostream>
#include <windows.h>
using namespace std;

class heapSort
{
public:

    void heapsorting(int *a, int n)
    {
        int i, temp;
        for (i = n; i >= 2; i--)
        {
            temp = a[i];
            a[i] = a[1];
            a[1] = temp;
            maxHeapify(a, 1, i - 1);
        }
    }
    void maxHeapify(int *a, int i, int n)
    {
        int j, temp;
        temp = a[i];
        j = 2*i;
        while (j <= n)
        {
            if (j < n && a[j+1] > a[j])
                j = j+1;
            if (temp > a[j])
                break;
            else if (temp <= a[j])
            {
                a[j/2] = a[j];
                j = 2*j;
            }
        }
        a[j/2] = temp;
        return;
    }
    void buildMaxheap(int *a, int n)
    {
        int i;
        for(i = n/2; i >= 1; i--)
        {
            maxHeapify(a, i, n);
        }
    }
};

int main()
{
    system("color 74");
    cout<<"\t     ____________________\n"
    <<"\t\tHeap Sort...!!\n"
    <<"\t     --------------------\n\n";
    int i = 0;
    int a[] = {1,9,2,56,34,678,1234,907,0,90,12,37,1,9,456,3567,12,890,10,5};
    int n = sizeof(a)/sizeof(int);

    cout<<"OUTPUT, Before Heap sort\n\n";
    for (i=0; i<n; i++)
        cout<<a[i]<<" ";

    cout<<"\n\n\n";

    heapSort h;
    h.buildMaxheap(a, n);
    h.heapsorting(a, n);

    cout<<"OUTPUT, After Heap Sort\n\n";
    for (i = 0; i <n; i++)
        cout<<a[i]<<" ";

    cout<<"\n";

}
