#include<iostream>
using namespace std;

int ** match_for_lcs(char * A, char * B, int a_len, int b_len, char *** taken )
{
    int ** match = new int * [a_len + 1]; for (int i = 0; i <= a_len; i++) match[i] = new int [b_len +1];
    char ** direction = new char * [a_len + 1]; for (int i = 0; i <= a_len; i++) direction[i] = new char [b_len +1];

    for (int i = 1; i <= a_len; i++)
    {
        match[i][0] = 0;
    }
    for (int j = 0; j <= b_len; j++)
    {
        match[0][j] = 0;
    }


    for (int i = 1; i <= a_len; i++)
    {
        for (int j = 1; j <= b_len; j++)
        {
            if (A[i-1] == B[j-1])
            {
                match[i][j] = match[i-1][j-1] + 1;
                direction[i][j] = 'd';
            }

            else if (match[i-1][j] >= match[i][j-1])
            {
                match[i][j] = match[i-1][j];
                direction[i][j] = 'u';
            }
            else
            {
                match[i][j] = match[i][j-1];
                direction[i][j] = 'l';
            }
        }
    }

    taken[0] = direction;
    return match;
}


void print_lcs(char ** dir, char *A, int i, int j)
{
    if (i == 0 or j == 0) return;

    if (dir[i][j] == 'd')
    {
        print_lcs(dir, A, i-1, j-1);
        cout<<A[i-1]<<" ";
    }
    else if (dir[i][j] == 'u')
        print_lcs(dir, A, i-1,j);
    else
        print_lcs(dir, A, i, j-1);
    
}

int main()
{
    int la = 7, lb = 6;
    char A[la] = {'A','B', 'C', 'B', 'D', 'A', 'B'}; // b c b a
    char B[lb] = {'B', 'D', 'C', 'A', 'B', 'A'};

    char *** dir = new char ** ;
    int ** res = match_for_lcs(A, B, la, lb, dir);
    

    for (int i = 0; i <= la; i++)
    {
        for (int j = 0; j <= lb; j++)
        {
            cout<<dir[0][i][j]<<" ";
        }
        cout<<endl;
        
    }
    cout<<endl;

    for (int i = 0; i <= la; i++)
    {
        for (int j = 0; j <= lb; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
        
    }
    cout<<endl;

    print_lcs(dir[0], A, la, lb);
 
    return 0;
}