#include <iostream>

using namespace std;

// Print All divisor of a number

//Input: 90
//Output: 1 90 2 45 3 30 5 18 6 15 9 10

//Sorted output: 1 2 3 5 6 9 10 15 16 18 30 45 90 [use a vector and sort]

//TC: O(sqrt(n)
//SC: O(1)
void printAllDivisor(int n)
{
    for(int i = 1; i*i <= 90; i++)
    {
        if( n % i == 0)
        {
            if(n/i == i)
                cout<<i<<" ";
            else
                cout<<i<<" "<<n/i<<" ";
        }
    }

    cout<<endl;
}

int main()
{
    int n = 90;

    printAllDivisor(n);
}
