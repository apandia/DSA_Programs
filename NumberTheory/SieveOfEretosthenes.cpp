#include <iostream>
#include <vector>

using namespace std;

// Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a range 1->n

//TC: O(n log logn)
//Note: Any query will take O(1) TC as info will be stored in vector
//SC: O(n)          [For storing prime vector]
void sieve(int n, vector<bool>& numbersArray)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(numbersArray[i])
        {
            for(int j = i*i; j <= n; j+= i)
            {
                numbersArray[j] = false;
            }
        }
    }
}

int main()
{
    int n = 100;

    vector<bool> numbers(n+1, true);

    numbers[0] = false;
    numbers[1] = false;

    sieve(n, numbers);

    int num = 7;

    if(numbers[num])
        cout<<num<<" is a prime Number"<<"\n";
    else
        cout<<num<<" is a not a prime Number"<<"\n";

    return 0;
}
