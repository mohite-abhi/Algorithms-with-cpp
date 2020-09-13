#include<iostream>

using namespace std;

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *arr, int start, int end)
{
    int pivot = end;
    int p_key = start;

    for (int i = start; i < end; i++)
    {
        if (arr[i] < arr[pivot])
        {
            swap(arr[p_key], arr[i]);
            p_key++;
        }
    }
    swap(arr[pivot], arr[p_key]);
    return p_key;
}

void quicksort(int *arr, int start, int end)
{
    if (start <end)
    {
        int pivot = partition(arr, start, end);

        quicksort(arr, start, pivot-1);
        quicksort(arr, pivot+1,end);
    }
    
    
}

int main()
{
    int ar[10] = {9,8,7,6,5,4,3,2,1,0};
    quicksort(ar,0,9);
    for (int i = 0; i < 10; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    return 0;
}