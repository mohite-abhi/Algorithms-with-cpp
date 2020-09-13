#include<iostream>
using namespace std;



void cp(int *ar1, int *ar2, int n)
{
    for (int i = 0; i < n; i++)
    {
        ar1[i] = ar2[i];
    }
    
}


int knapsack(int * w, int * v, int W, int Tw, int Tv, int * res, int * fin_res, int n, int & omax )
{
    if (Tw <= W)
    {
        if (Tv > omax)
        {
            omax = Tv;
            cp(fin_res, res, n);
        }
        return Tv;
    }
    
    int temp, max = 0;

    for (int i = 0; i < n; i++) if (res[i])
    {   
        res[i] = 0;
        temp = knapsack(w, v, W, Tw - w[i], Tv - v[i], res, fin_res, n, omax);
        res[i] = 1;

        if (temp > max)
        {
            max = temp;
        }
    }

    return  max;
    
}

int sm(int *ar, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += ar[i];
    }
    return s;
}

int main()
{
    int n = 6;
    int w[n] = {1,2,3,8,7,4};
    int v[n] = {20,5,10,40,15,25};
    int W = 10;

    int res[n] = {1, 1, 1, 1, 1, 1};
    int *fin_res = new int[n];

    int Tw = sm(w, n);
    int Tv = sm(v, n);

    int omax = 0;

    //cout<<sum_ar(w,res,0,3);
    knapsack(w, v, W, Tw, Tv, res, fin_res, n, omax);

    for (int i = 0; i < n; i++)
    {
        cout<<fin_res[i]<<"  ";
    }
    
    return 0;
}
