#include <iostream>
#include <vector>

using namespace std;

//Find the nth element in Fibonacci series using DP
//Fibonacci series: 0 1 1 2 3 5 8 13 ...

//5th Number: 5

//Memoization
//TC: O(N)
//      Only the left side of recusrsion will be executed.
//      For right side ie.e the overlappting sub problem vale will be taken from dp, so O(1)
//SC: O(N) + O(N)
//      O(N) for recursive stack space
//      O(N) for dp data structure
int funcM(int n, vector<int>& dp)
{
    if(n<=1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = funcM(n-1,dp) + funcM(n-2,dp);
}

int memoization(int n)
{
    vector<int> dp(n+1,-1);

    return funcM(n,dp);
}

//Tabulation
//TC: O(N)
//      For loop till index N
//SC: O(N)
//      O(N) for dp data structure
int tabulation(int n)
{
    vector<int> dp(n+1,-1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//Tabulation Space Optimized
//TC: O(N)
//      For loop till index N
//SC: O(1)  [No extra space used]
int tabulationOptimized(int n)
{
    int prev2 = 0;
    int prev1 = 1;

    for(int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n = 7;

    cout<<memoization(n)<<endl;

    cout<<tabulation(n)<<endl;

    cout<<tabulationOptimized(n)<<endl;

    return 0;
}
