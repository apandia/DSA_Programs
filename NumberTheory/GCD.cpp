#include <iostream>
#include <vector>

using namespace std;

// Find GCD of 2 numbers

// Euclidean Algorithm

/*
Input: 36 60

Output:
GCD of (36, 60) = 12
*/

//TC: O(log min(a, b))
//SC: O(log min(a, b))      [Auxilary stack space]
int gcd(int a, int b)
{
    if (b == 0)
        return a;

   return gcd(b, a %b);
}

int main()
{
    int a = 36;
    int b = 60;

    cout<<"GCD of ("<<a<<", "<<b<<") = "<<gcd(a,b)<<endl;

    return 0;
}
