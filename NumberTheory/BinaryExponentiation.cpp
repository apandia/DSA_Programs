#include <iostream>

using namespace std;

// Find binary exponention

/*
Input: 2 ^ 10

Output: 1024
*/

//Brute Force Method
//TC: O(N) ans input number will be multiplied n times

//Optimized solution
/*Idea:
        result      base    power
           1         2       10             n == even, no change in base, devide power by 2
           1         4        5             n == odd, result = result*base, base = base square, power -= 1
           4         4        4
           4         16       2
           4        256       1
         1024       256       0
*/
//TC: O(log n)
//SC: O(1)
int binaryExponentiation(int a, int n)
{
    int result = 1;

    while(n)
    {
        if(n%2 != 0)
        {
            result *= a;
            n--;
        }
        //else              else condition is not required as n-- will make n as even. so we can directly execute even case after odd case
        {
            a *= a;
            n /=2;
        }
    }

    return result;
}

int main()
{
    int a = 2;
    int n = 10;

    cout<<a<<"^"<<n<<" = "<<binaryExponentiation(a, n)<<endl;

    return 0;
}
