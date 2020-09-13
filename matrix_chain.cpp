#include<iostream>
using namespace std;

void matrix_order(int * p, int ** c, int ** s, int n)
{
    int temp;
    

    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1 ; i++)
        {
            int j = i+l -1;

            for (int k = i; k <= j-1; k++)
            {
                temp = c[i][k] + c[k+1][j] + p[i-1]*p[k]*p[j];

                if(k == i)
                {
                    c[i][j] = temp;
                    s[i][j] = k;
                }

                else if (temp < c[i][j])
                {
                    c[i][j] = temp;
                    s[i][j] = k;
                }
                
            }
            
        }
        
    }
    
}


void print_matrix_chain(int **s, int i, int j)
{
    if (i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        print_matrix_chain(s, i, s[i][j]);                
        print_matrix_chain(s, s[i][j] + 1, j);
        cout<<")";
    }
    
}


int main()
{
    int n = 6;
    int p[7] = {30,35,15,5,10,20,25};

    int **c;
    int **s;

    c =new int* [n+1];
    for (int i=0;i<=n;i++) c[i] = new int [n+1];
    s = new int* [n+1];
    for (int i=0;i<=n;i++) s[i] = new int [n+1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            s[i][j] = 0;
            c[i][j] = 0;
        }
        
    }
    
  


    matrix_order(p, c, s, 6);

print_matrix_chain(s, 1, 6);
    return 0;
}

