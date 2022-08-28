#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define mod 1000000007

// Find Power of Matrix.

// Give a square matrix M and a power N find M raised to N i.e. multiply the matrix with itself N times

/*
Input:
2
2 3
1 0
1 1
3 3
1 0 4
1 2 2
0 4 4

Output:
1 0
3 1
17 112 116
15 88 100
28 144 160
*/
//TC: O(m^3 log n)                  [O(m^3 * n) for Brute force]
//SC: O(m*m) + O(m*m) + O(m*m)      [matrix, identityMatrix and result vector]
void matrixMultiplication(vector<vector<ll>>& A, vector<vector<ll>>& B, int m)
{
    vector<vector<ll>> result(m, vector<ll>(m, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++) 
            {
                //result[i][j] += A[i][k] * B[k][j];
                result[i][j] = (result[i][j] % mod + ((A[i][k] % mod) * (B[k][j] % mod) % mod)) % mod;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            B[i][j] = result[i][j];
        }
    }
}

void solve()
{
    int m, n;
    cin >> m >> n;

    vector<vector<ll>> mat(m, vector<ll>(m));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<ll>> identityMatrix(m, vector<ll>(m, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                identityMatrix[i][j] = 1;
            }
        }
    }

    // Below for loop can be optimized to O(log n)
    #ifdef BRUTE_FORCE
    for (int i = 0; i < n; i++)
    {
        matrixMultiplication(mat, identityMatrix, m);
    }
    #else
    while (n)
    {
        if (n % 2 != 0)
        {
            matrixMultiplication(mat, identityMatrix, m);
            n--;
        }
        else
        {
            matrixMultiplication(mat, mat, m);
            n /= 2;
        }
    }
    #endif

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<identityMatrix[i][j]<< " ";
        }
        cout << "\n";
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

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        solve();
    }

    return 0;
}
