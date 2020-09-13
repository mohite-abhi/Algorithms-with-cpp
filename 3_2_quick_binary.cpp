#include <iostream>
#include<fstream>
using namespace std;


template <class type>
type * make_arr(int n)
{
    type *arr = new type[n];
    cout<<"Q. give "<<n<<"  numbers : \n";
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    return arr;
}


void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}


int partition(int *arr, int p, int r, int * init_pos)
{
    int piv = arr[r], j = p;

    for (int i = p; i < r; i++)
        if (arr[i] <= piv)
        {
            swap(arr[i], arr[j]);
            swap(init_pos[i],init_pos[j]);
            j++;
        }
    swap(arr[j],arr[r]); 
    swap(init_pos[j],init_pos[r]);

    return j;
}


void quicksort(int * arr, int p, int r, int * init_pos)
{   
   if (p<r)
   {
       int piv = partition(arr, p, r, init_pos);

       quicksort(arr, p, piv-1, init_pos);
       quicksort(arr, piv+1, r, init_pos);
   }
}


int binary_search(int *ar, int find, int end)
{
    int start = 0, mid, elem = find+1;
       
    while(elem != find && start <=end)
    {
        mid = (start+end)/2;
        elem = ar[mid];
        if (elem < find)
        {
            start = mid+1;
        }
        else if (elem > find)
        {
            end = mid-1;
        }
    }

    if (elem != find) 
    {
        cout<<"value not found error!";
        return -1;
    }
    
    return mid;
}


void display_arr(int * arr, int n)
{
    cout<<"Ans. displaying final result : \n>>";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<"  ";
    cout<<endl;   
}


class student
{
    public:
        int id;
        char name[20];
        int add() { cout<<"Id -> "; cin>>id; cout<<"  Name -> "; cin>>name; cout<<endl; return id; }
        void show(){ cout<<"Id -> "<<id<<"  Name -> "<<name<<endl; }
};


//============================for inputting 10 number and sorting using quick sort==================
void task_1(int n)
{
    int *arr = make_arr<int>(n), no_use[n]={};

    quicksort(arr,0,n-1,no_use);

    ofstream f1("temp.txt");
    for (int i = 0; i < n; i++)
    {
        f1<<arr[i]<<" ";
    }

    f1.close();

    display_arr(arr, n);
}

//============================for inputting 8 student record =======================================

void task_2(int n) 
{
    student stud[n];
    int * init_pos = new int[n];
    int ind[n];

    for (int i = 0; i < n; i++)
    {
        init_pos[i] = i;
        ind[i] = stud[i].add();
    }   

    quicksort(ind, 0, n, init_pos);

    for (int i = 0; i < n; i++)
    {
       stud[init_pos[i]].show();
    }
}


//============================for binary searching =================================================

void task_3(int n)
{   
    int take, arr[n], k;
    cout<<endl<<"give a number to search from the array :\n";

    ifstream f1("temp.txt");
    for (int i = 0; i < n; i++)
    {   
        f1>>arr[i];
        cout<<arr[i]<<"  ";
    }
    f1.close();
    cout<<"\n>>"; cin>>take;

    k = binary_search(arr,take,n-1);
    cout<<"your number is found at index "<<k+1;
}




int main()
{ 
    int choice=5, inp1=-1, inp2;
    
    while (choice != 4)
    {
        cout<<"\nchoose :\n1. input and sort\t2. input student record\n3. position query of (1) \t4. exit\n"; cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"give no.of inputs : "; cin>>inp1; cout<<endl;
                task_1(inp1);
                break;
            case 2:
                cout<<"give no.of students to input : "; cin>>inp2; cout<<endl;
                task_2(inp2);
                break;
            case 3:
                if (inp1 == -1)
                {
                    cout<<"first runn task 1 for this!";
                    break;
                }
                
                task_3(inp1);
                break;
            default:
                break;
        }
    }
    
    return 0;
}