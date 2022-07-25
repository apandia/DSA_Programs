#include <iostream>
#include <vector>

using namespace std;

// Find minimum energy used by the frog to jump from stairs 0 to N-1
// Frog can either climb 1 or 2 step each time.

// Energy consudedm in a jump from index i to i+1= abs(height[i+1] - height[i])

/*
Input height = {30, 10, 60, 10, 60, 50};
N = 6 (poistion ie 5th index)

Output: 40
0 --> 2 --> 4 --> 5
  30    0     10            Total = 40
*/

// 1. Normal recusrsive solution (Might give TLE for large input)
//    TC and SC same as Memoization but will benefit for overlapping sub problem
int minEnergy(int n, vector<int>& height)
{
    if(n == 0)
    {
        return 0;
    }

    int jumpOnePosition = minEnergy(n-1, height) + abs(height[n] - height[n-1]);

    int jumpTwoPosition = INT_MAX;
    if(n > 1)
        jumpTwoPosition = minEnergy(n-2, height) + abs(height[n] - height[n-2]);

    return min(jumpOnePosition, jumpTwoPosition);
}

//2. Memoization
//TC: O(N)
//      Only the left side of recusrsion will be executed.
//      For right side ie.e the overlappting sub problem vale will be taken from dp, so O(1)
//SC: O(N) + O(N)
//      O(N) for recursive stack space
//      O(N) for dp data structure
int minEnergyM(int n, vector<int>& height, vector<int>& dp)
{
    if(n == 0)
    {
        return 0;
    }

    if(dp[n] != -1)
        return dp[n];

    int jumpOnePosition = minEnergyM(n-1, height, dp) + abs(height[n] - height[n-1]);

    int jumpTwoPosition = INT_MAX;
    if(n > 1)
        jumpTwoPosition = minEnergyM(n-2, height, dp) + abs(height[n] - height[n-2]);

    return dp[n] = min(jumpOnePosition, jumpTwoPosition);
}

//3. Tabulation
//TC: O(N)
//      For loop till index N
//SC: O(N)  [for dp vector]
int minEnergyT(int n, vector<int>& height, vector<int>& dp)
{
    dp[0] = 0;

    for(int i =1; i < n; i++)
    {
       int jumpOnePosition = dp[i-1] + abs(height[i] - height[i-1]);

       int jumpTwoPosition = INT_MAX;
       if(i > 1)
           jumpTwoPosition = dp[i-2] + abs(height[i] - height[i-2]);

       dp[i] = min(jumpOnePosition, jumpTwoPosition);
    }

    return dp[n-1];
}

//4. Tabulation with space optimization
//TC: O(N)
//      For loop till index N
//SC: O(1)  [No extra space used]
int minEnergyTO(int n, vector<int>& height)
{
    int prev1 = 0;
    int prev2 = 0;

    for(int i =1; i < n; i++)
    {
       int jumpOnePosition = prev1 + abs(height[i] - height[i-1]);

       int jumpTwoPosition = INT_MAX;
       if(i > 1)
           jumpTwoPosition = prev2 + abs(height[i] - height[i-2]);

       int curr = min(jumpOnePosition, jumpTwoPosition);

       prev2 = prev1;
       prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};

    int n= height.size();

    //Recursive
    cout<<"Minimum Energy Used = "<<minEnergy(n-1, height)<<endl;

    //Memoization
    vector<int> dpm(n, -1);
    cout<<"Minimum Energy Used = "<<minEnergyM(n-1, height, dpm)<<endl;

    //Tabulation
    vector<int> dpt(n, -1);
    cout<<"Minimum Energy Used = "<<minEnergyT(n, height, dpt)<<endl;

    cout<<"Minimum Energy Used = "<<minEnergyTO(n, height)<<endl;
}
