#include<iostream>
using namespace std;

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}


void max_prioritize(int *ar, int i, int len, int *val)
{
    int l = 2*i +1;
    int r = 2*i + 2;
    int largest = i;

    if (l<len and ar[l] > ar[largest])
    {
        largest = l;
    }
    if (r<len and ar[r] > ar[largest])
    {
        largest = r;
    }
    swap(ar[i], ar[largest]);
    swap(val[i], val[largest]);
    if (largest != i)
    {
        max_prioritize(ar, largest, len, val);
    }

}

void build_priority_queue(int * ar, int len,int * val)
{
    for (int i = len/2-1; i >=0; i--)
    {
        max_prioritize(ar, i, len, val);
    }
    
}

void show_priority_min(int *ar, int len, int *val)
{
    int min=0;
    for (int i = 1; i < len; i++)
    {
        if(ar[i]<ar[min])
        {
            min = i;
        }   
    }
    cout<<ar[min]<<" : "<<val[min];
}

void extract_priority_max(int *ar, int &len, int *val)
{
    if (len==0)
    {
        cout<<"heap empty!";return;
    }
    
    cout<<(ar[0])<<" "<<val[0];
    swap(ar[0],ar[len-1]);
    swap(val[0],val[len-1]);
    max_prioritize(ar,0,--len, val);
}

int parent(int n) 
{
    return (n-1)/2;
}
void increase_pri_key(int*ar, int i, int key, int len, int *val)
{
    if (key < ar[i])
    {
        cout<<"new key should not be smaller than previous key!";return;
    }

    ar[i] = key;

    while (i>0 and ar[parent(i)] < ar[i] )
    {
        swap(ar[i],ar[parent(i)]);
        swap(val[i], val[parent(i)]);
        i=parent(i);
    }    
}

void insert_key_pri(int*ar, int k, int v,int &len, int * val)
{
    len += 1;

    ar[len-1] = k;
    val[len-1] = v;
    increase_pri_key(ar,len-1,k,len,val);
}

void show(int*ar, int len, int * val)
{
    for (int i = 0; i < len; i++)
    {
        cout<<ar[i]<<" -> "<<val[i]<<endl;
    }
    
}
int main()
{
    int n;
    int * num = new int[500];
    int * val = new int[500];


    int priority_lenth=0, choice=1;
 
    build_priority_queue(num,priority_lenth,val);
    while (choice/4 == 0)
    {
        cout<<"\n1. show \t2. increase key \n3.insert\t4. exit\n";cin>>choice;
        switch (choice)
        {
        case 1:
            show(num,priority_lenth,val);
            break;
        case 2:
            int ii,kk;
            cout<<"old pos : ";cin>>ii;cout<<"new key :";cin>>kk;
            increase_pri_key(num,ii,kk,priority_lenth,val);
            break;
        case 3:
            int kkk,vv;
            cout<<"key and val : ";cin>>kkk>>vv;
            insert_key_pri(num,kkk,vv,priority_lenth,val);
            break;
        case 0:
            extract_priority_max(num, priority_lenth,val);
            break;
        default:
            break;
        }
    }
    

    


    return 0;
}