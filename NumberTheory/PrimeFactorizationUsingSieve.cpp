#include <iostream>
#include <vector>

using namespace std;

// Find Prime Factorization using Sieve

/*
Input: 315

Output: 3 3 5 7
*/

//TC: O(n log(n))
//SC: O(n)
void sieve(int n, vector<int>& numbersArray)
{
    for(int i = 2; i <= n; i++)
    {
        if(numbersArray[i] == -1)
        {
            for(int j = i; j <= n; j+= i)
            {
                if(numbersArray[j] == -1)
                {
                    numbersArray[j] = i;
                }
            }
        }
    }
}

void primeFactorization(int n, vector<int>& arr)
{
    while (n != 1)
    {
        cout<<arr[n]<<" ";

        n = n/arr[n];
    }

    cout<<endl;
}

int main()
{
    int maxN = 1000000;

    vector<int> numbers(maxN+1, -1);

    numbers[0] = 1;
    numbers[1] = 1;

    sieve(maxN, numbers);

    int num = 315;
    cout<<"Prime Factorization of "<<num<<" = ";
    primeFactorization(num, numbers);

    return 0;
}
