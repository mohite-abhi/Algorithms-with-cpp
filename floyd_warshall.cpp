#include<iostream>
using namespace std;


int ** floyd_warshall(int ** W, int n)
{
    int **D_old = new int *[n];
    for (int i = 0; i < n; i++)
        D_old[i] = new int [n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            D_old[i] = W[i];
        
    

    int **D_new = new int *[n];
    for (int i = 0; i < n; i++)
        D_new[i] = new int [n];
    

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                D_new[i][j] = min(D_old[i][j], D_old[i][k] + D_old[k][j]);
            }
            
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                D_old[i] = D_new[i];
    }
    
    return D_new;
    
}

int main()
{

    int ** mat1 = new int * [5];
    for (int i = 0; i < 5; i++)
    {
        mat1[i] = new int[5];
    }
    

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>mat1[i][j];
        }
    }

    int ** newmat = floyd_warshall(mat1, 5);

    cout<<endl<<endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<newmat[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    

return 0;
}
