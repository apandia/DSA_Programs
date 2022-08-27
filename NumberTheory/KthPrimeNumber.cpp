#include <iostream>
#include <vector>

using namespace std;

// Find the Kth Prime Number where 1 <= K <= 5000000

/*
Input:
1
10
100
1000
10000
100000
1000000

Output:
2
29
541
7919
104729
1299709
15485863
*/

//TC: O(n log logn)
//Note: Any query will take O(1) TC as info will be stored in vector
//SC: O(n)+O(n)          [For storing numbers array and prime vector]
void sieve(int n, vector<bool>& numbersArray, vector<int>& primes)
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

    for(int i = 2; i <= n; i++)
    {
        if(numbersArray[i])
        {
            primes.push_back(i);
        }
    }
}

int main()
{
    int n = 90000000; //To get 5000000 prime number we might need numbers upto 9000000

    vector<bool> numbers(n+1, true);
    vector<int> primes;

    numbers[0] = false;
    numbers[1] = false;

    sieve(n, numbers, primes);

    int k = 1000000;

    cout<<k<<"th Prime Number = "<<primes[k-1]<<"\n"; //Kth prime number will be at index K-1

    return 0;
}
