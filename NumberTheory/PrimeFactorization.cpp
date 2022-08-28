#include <iostream>

using namespace std;

//#define PRINT_IN_EXPONENT

// Find Prime Factorization of n

/*
Input: 100

Output:
(2^2) (5^2) = [4*25]  using expoent

2 2 5 5               without exponent
*/

//Brute Force Method
//TC: O(log n)  if number is not prime as value of n will keep on reducing in inside while loop
//    O(n)      if number is prime. for loopwill be excuted for n times
//SC: O(1)
void primeFact(int n)
{
    for(int i = 2; i <=n; i++)
    {
        if(n%i == 0) //TC: constant
        {
            //We will come inside this if condition only for i where i is prime for eg i = 2 and 5
            // For a big prime number ~(6*(10^9)), it come come 10 times
            //How --> Bacause 2*3*5*7*11*13*17*19*23*29 = 6,469,693,230 which is greater than (6*(10^9))
            int cnt = 0;
            while(n%i == 0)     //TC: log (n) base i
            {
#ifndef PRINT_IN_EXPONENT
                cout<<i<<" ";
#endif
                cnt++;
                n /= i;
            }
#ifdef PRINT_IN_EXPONENT
            cout<<"("<<i<<"^"<<cnt<<") ";
#endif
        }
    }
    cout<<endl;
}

//Optimized solution
//Idea -> If n is composite number, then there will atleast be one prime number which is less than sqroot of n
//4 = 2*2
//6 = 2*3 (sqrt(6) = 2.xxx)
//TC: O(sqrt(n))
//SC: O(1)
void primeFactorization(int n)
{
    for(int i = 2; i*i <=n; i++)
    {
        if(n%i == 0)
        {
            int cnt = 0;
            while(n%i == 0)
            {
#ifndef PRINT_IN_EXPONENT
                cout<<i<<" ";
#endif
                cnt++;
                n /= i;
            }
#ifdef PRINT_IN_EXPONENT
            cout<<"("<<i<<"^"<<cnt<<") ";
#endif
        }
    }

    if(n > 1)
    {
#ifdef PRINT_IN_EXPONENT
        cout<<"("<<n<<"^1"<<") ";
#else
        cout<<n<<" ";
#endif
    }

    cout<<endl;
}

int main()
{
    int n = 315;

    cout<<"Prime Factorization of "<<n<<" = ";
    primeFactorization(n);
    primeFact(n);

    return 0;
}
