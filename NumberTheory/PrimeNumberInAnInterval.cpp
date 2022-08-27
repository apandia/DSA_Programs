#include <iostream>
#include <math.h>

using namespace std;

// Finf all prime number in an interval L and T
/*
Input:
L = 1, R = 10

output:
2, 3, 5, 7
*/


//TC: O(sqrt(n))
//      O(sqrt(n)): loop till sqroot of n while trying to find pairs
//SC: O(1)
bool isPrime(int n)
{
    if(n == 1)
        return false;

    for(int i = 2; i*i <= n ; i++)
    {
        if(n%i == 0)
            return false;
    }

    return true;
}

int main()
{
    int l = 2;
    int r = 10;

    for(int i = l; i <= r; i++)
    {
        if(isPrime(i))
            cout<<i<<" ";
    }

    cout<<endl;

    return 0;
}
