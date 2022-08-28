#include <iostream>
#include <vector>

using namespace std;

// Find Prime Prime Number
// A number X is Prime Prime if number of prime numbers from 1 to X (inclusive) are prime
// 3 is a prime prime as prime numbers before 3 are 2 and 3. So the count is 2 and 2 is prime. So 3 is prime prime

/*
Input:
2       Num text case
3 10
4 12

Output:
4
5
*/

void sieve(int n, vector<bool>& numbersArray, vector<int>& primeprime)
{
    for (long long int i = 2; i*i <= n; i++)
    {
        if (numbersArray[i])
        {
            for (long long int j = i*i; j <= n; j += i)
            {
                numbersArray[j] = false;
            }
        }
    }

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (numbersArray[i])
        {
            count++;
        }

        if (numbersArray[count])
        {
            primeprime[i] = 1;
        }
    }

    //Commulative addition approach to solve TLE
    //Each index of primeprime vector contains sum of value upto that index
    for (int i = 1; i <= n; i++)
    {
        primeprime[i] += primeprime[i - 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    int n = 1000000;

    vector<bool> numbers(n + 1, true);
    vector<int> primeprime(n+1);

    numbers[0] = false;
    numbers[1] = false;

    sieve(n, numbers, primeprime);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        int l, r;
        cin >> l >> r;

        int count = 0;
        //If tc is of range 10^6 and both l and r of range 10^6 then below loop will give TLE
        // So use commulative addition approach in primeprimevector
        /*for (int i = l; i <= r; i++)
        {
            count += primeprime[i];
        }
        cout << count << "\n";*/

        //Using commulative sum approach
        cout << primeprime[r] - primeprime[l-1] << "\n";
    }

    return 0;
}
