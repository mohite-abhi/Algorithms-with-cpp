#include<iostream>
using namespace std;

int * rec_act_sel(int *s, int *f, int n, int k = 0, int i = 1, int size = 0)
{
    int * res;
    if (k+i > n-1)
    {
        res = new int[size+1];
        res[0] = size;
        return res;
    }
    if (s[k+i] >= f[k])
    {
        res = rec_act_sel(s, f, n, k+i, 1, size+1);
        res[size+1] = k+i;
        //cout<<"size = "<<size<<" val = "<<res[size];

    }
    else
    {
        res = rec_act_sel(s, f, n, k, i+1, size);
        //cout<<"howwdy";
    }
    
    return res;

}

int main()
{
    int s[12] = {0,1,3,0,5,3,5,6, 8, 8, 2, 12};
    int f[12] = {0,4,5,6,7,9,9,10,11,12,14,16};
    
    int *res = rec_act_sel(s, f, 12);
    
    for (int i = 1; i <= res[0]; i++)
    {
        cout<<res[i]<<" ";
    }
    


    return 0;

}