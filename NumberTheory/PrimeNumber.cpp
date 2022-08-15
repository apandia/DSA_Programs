#include <iostream>
#include <math.h>

using namespace std;

// Check if a number is prime or not
// Prime Number -> if the number is diviible by only 1 and the number itself

//TC: O(n)    //to iterate from numbers 2 to n-1 to find if it is divisible by any other number
//SC: O(1)
bool isPrime1(int n)
{
    if(n == 1)
        return false;

    for(int i = 2; i < n ; i++)
    {
        if(n%i == 0)
            return false;
    }

    return true;
}

//TC: O(sqrt(n)) + O(log n)
//      O(sqrt(n)): loop till sqroot of n while trying to find pairs
//      O(log n)  : complexity of sqrt function of math module
//SC: O(1)
bool isPrime2(int n)
{
    if(n == 1)
        return false;

    int s = (int) sqrt(n);

    for(int i = 2; i < s ; i++)
    {
        if(n%i == 0)
            return false;
    }

    return true;
}


//TC: O(sqrt(n))
//      O(sqrt(n)): loop till sqroot of n while trying to find pairs
//SC: O(1)
bool isPrime3(int n)
{
    if(n == 1)
        return false;

    for(int i = 2; i*i < n ; i++)
    {
        if(n%i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n = 7;

    if(isPrime3(n))
        cout<<n<<" is Prime Number"<<"\n";
    else
        cout<<n<<" is not Prime Number"<<"\n";

    return 0;
}
