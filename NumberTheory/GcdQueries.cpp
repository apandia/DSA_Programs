#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define lli long long int
#define mod 1000000007
#define vi vector<int>
#define vlli vector<long long int>
//#define vvarraylli vector<vector<long long int>> arr(m, vector<long long int>(m));

// Gcd Queries

/*
Input:
1
3 3
2 6 9
1 1
2 2
2 3

Output:
3
1
2
*/

int gcd(int a, int b )
{
    if (b == 0)
        return a;

    return gcd(b, a % b);    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        int n, q;
        cin >> n>>q;

        vi arr(n + 1, 0); 

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        // l and r follows 1 based indexing, so we need to store cgd from i=1 to n.
        // We also need 0 and n+1 index of array, so initialialized to n+2.
        // Prefix array needs 0th element and suffix needs n+1 to be initialized with 0
        vi prefix(n + 2, 0);
        vi suffix(n + 2, 0);

        for (int i = 1; i <= n; i++)
        {
            prefix[i] = gcd(prefix[i - 1], arr[i]);
        }

        for (int i = n; i >= 1; i--)
        {
            suffix[i] = gcd(arr[i], suffix[i + 1]);
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            cout << gcd(prefix[l - 1], suffix[r + 1])<<"\n";
        }
    }

    return 0;
}
