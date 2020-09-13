#include<iostream>
using namespace std;

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}


void max_heapify(int * ar, int i, int len)
{   
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < len and ar[l] > ar[i])
    {
        largest = l;
    }
    if (r < len and ar[r] > ar[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(ar[largest], ar[i]);
        max_heapify(ar, largest, len);
    }
}


void build_max_heap(int * ar, int len)
{
    for (int i = len/2-1; i >=0; i--)
    {
        max_heapify(ar, i, len);
    }
}



void heap_sort(int *ar, int len)
{
    build_max_heap(ar, len);
    int ln = len-1;
    for (int i = 0; i < len; i++)
    {   
        swap(ar[0],ar[ln]);
        max_heapify(ar,0,ln);
        ln -= 1;
    }
}

int* inp(int n)
{   
    cout<<"give "<<n<<" numbers :";
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>ar[i];
    }
    return ar;
}

void dis(int * ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    
}

int main()
{
    int * num, n;
    cout<<"give no. of tests to sort :"; cin>>n;
    num = inp(n);
    heap_sort(num, n);
    dis(num,n);
}