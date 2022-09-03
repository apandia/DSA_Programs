#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define lli long long int
#define mod 1000000007
#define vi vector<int>
#define vlli vector<long long int>

// Given a value of a and n, find the last digit for a ^n
// a = 8, n (0  ≤  n  ≤  10^9).

void power(lli a, lli n, lli modulo)
{
    lli result = 1;

    while (n)
    {
        if (n % 2 != 0)
        {
            result = (result * a) % modulo;
            n--;
        }

        a = (a * a) % modulo;
        n /= 2;
    }

    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    power(8, n, 10);

    return 0;
}
