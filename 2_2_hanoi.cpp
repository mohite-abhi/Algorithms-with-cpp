#include<iostream>
using namespace std;

void hanoi(int n, char from, char to, char thru)
{
    if (n==1)
    {
        cout<<"move 1 from "<<from<<" to "<<to<<endl;
        return;
    }

    hanoi(n-1, from, thru, to);
    cout<<"move "<<n<<" from "<<from<<" to "<<to<<endl;
    hanoi(n-1, thru, to, from);
    
}
int main()
{
    hanoi(3,'a', 'b', 'c');
    return 0;
}