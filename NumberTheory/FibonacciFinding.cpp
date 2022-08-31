#include <iostream>
#include <vector>

using namespace std;

#define ll long ll
#define lli long long int
#define mod 1000000007
#define vi vector<int>
#define vlli vector<long long int>
//#define vvarraylli vector<vector<long long int>> arr(m, vector<long long int>(m));

// Fibonacci Finding - Find the nth element in Fibonaci series
/* Rule:

[f1 f2] * | P Q | ^ n-1 = [f2 f3]
          | R S |

PQRS is from Transition matrix.
Steps:
1. Find the Transition matrix
2. Multiply the transition matrix (n-1) times
3. multiply input matrix [f1 f2] and Transition matrix to get the output

[f1*P+f2*R f1*Q+f2+S = f2 f3
=> f3 = f1*Q+ f2*S

Transition MAtrix for this problem = | 0 1 |
                                     | 1 1 |

*/

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
//TC: O(m^3 log n)                  [Note: O(m^3 * n) for Brute force approach]
//SC: O(m*m) + O(m*m) + O(m*m)      [matrix, identityMatrix and result vector]
void matrixMultiplication(vector<vector<lli>>& A, vector<vector<lli>>& B, int m)
{
    vector<vector<lli>> result(m, vector<lli>(m, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for(int k = 0; k < m; k++)
            {
                result[i][j] = (result[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
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

void solve(int a, int b, int n)
{
    vlli input(2);
    input[0] = a;
    input[1] = b;

    if (n < 2)
    {
        cout << input[n]<<endl;
        return;
    }

    vector<vector<lli>> transitionMatrix(2, vector<lli>(2, 1));
    transitionMatrix[0][0] = 0;

    vector<vector<lli>> identityMatrix(2, vector<lli>(2, 0));
    identityMatrix[0][0] = 1;
    identityMatrix[1][1] = 1;

    int power = n - 1;

    while (power)
    {
        if (power % 2 != 0)
        {
            matrixMultiplication(transitionMatrix, identityMatrix, 2);
            power--;
        }

        matrixMultiplication(transitionMatrix, transitionMatrix, 2);
        power /= 2;
    }

    int result = (input[0] * identityMatrix[0][1] + input[1] * identityMatrix[1][1]) % mod;
    cout << result<<endl;
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
        int a, b, n;
        cin >> a >> b >> n;

        solve(a, b, n);
    }

    return 0;
}
