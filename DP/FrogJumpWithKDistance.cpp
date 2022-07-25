#include <iostream>
#include <vector>

using namespace std;

// Find minimum energy used by the frog to jump from stairs 0 to N-1
// Frog can either climb upto K steps each time ie. 1,2,3,4 ...K

// Energy consudedm in a jump from index i to i+1= abs(height[i+1] - height[i])

/*
Input height = {30, 10, 60, 10, 60, 50};
K = 2

Output: 40
*/

// 1. Normal recusrsive solution
//    TC and SC same as Memoization except for overlapping sub problem
int minEnergy(int n, vector<int>& height, int k)
{
    if(n == 0)
    {
        return 0;
    }

    int minEnergyUsed = INT_MAX;

    for(int j = 1; j <=k ; j++)
    {
        if(n-j >= 0)
        {
            int current = minEnergy(n-j, height, k) + abs(height[n] - height[n-j]);
            minEnergyUsed = min(current, minEnergyUsed);

        }
    }

    return minEnergyUsed;
}

//2. Memoization
//TC: O(N * K)
//      Only the left side of recusrsion will be executed.
//      For right side ie.e the overlappting sub problem vale will be taken from dp, so O(1)
//      For each new problem we are running K loop
//SC: O(N) + O(N)
//      O(N) for recursive stack space
//      O(N) for dp data structure
int minEnergyM(int n, vector<int>& height, int k, vector<int>& dp)
{
    if(n == 0)
    {
        return 0;
    }

    if(dp[n] != -1)
        return dp[n];

    int minEnergyUsed = INT_MAX;

    for(int j = 1; j <=k ; j++)
    {
        if(n-j >= 0)
        {
            int current = minEnergy(n-j, height, k) + abs(height[n] - height[n-j]);
            minEnergyUsed = min(current, minEnergyUsed);

        }
    }

    return dp[n] = minEnergyUsed;
}

//3. Tabulation
//TC: O(N * K)
//      For loop till index N and K steps for each new sub problem
//SC: O(N)  [for dp vector]
int minEnergyT(int n, vector<int>& height, int k, vector<int>& dp)
{
    dp[0] = 0;

    for(int i =1; i < n; i++)
    {
        int minEnergyUsed = INT_MAX;

        for(int j = 1; j <=k ; j++)
        {
            if(i-j >= 0)
            {
                int current = minEnergy(i-j, height, k) + abs(height[i] - height[i-j]);
                minEnergyUsed = min(current, minEnergyUsed);

            }
        }

        dp[i] = minEnergyUsed;
    }

    return dp[n-1];
}

// TODO: Space optimization using vector to carry upto n-k prev variables. So that the SC = O(K)
//Note: Worst case will still be O(N) where K = N

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};

    int n= height.size();
    int k = 2;

    //Recursive
    cout<<"Minimum Energy Used = "<<minEnergy(n-1, height, k)<<endl;

    //Memoization
    vector<int> dpm(n, -1);
    cout<<"Minimum Energy Used = "<<minEnergyM(n-1, height, k, dpm)<<endl;

    //Tabulation
    vector<int> dpt(n, -1);
    cout<<"Minimum Energy Used = "<<minEnergyT(n, height, k, dpt)<<endl;
}
