#include <iostream>
#include <vector>

using namespace std;

// Find distinct ways to climb a staircase of n steps.
// You can either climb 1 or 2 step each time.

// The problem can be implemented as Fibonacci problem with base case 0 and 1 = 1
// In Fibonacci base[0] = 0

//Note: If the input size is bigger say 10^18, then use Matric exponentiation as we can not iterate over 10^18 for loop

//TC: O(N)
//      For loop till index N
//SC: O(1)  [No extra space used]
int climbStairs(int n)
{
    int prev2 = 1;
    int prev1 = 1;

    for(int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n = 2;

    cout<<climbStairs(n)<<endl;

    return 0;
}
