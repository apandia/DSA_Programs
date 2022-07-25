#include <iostream>
#include <vector>

using namespace std;

// Find max amount a Robber can rob from a housing society. he can not run adjacent houses. 
// 1st and last houses are adjacent i.e the housing society is circular. So can not run 1st and last at same time but can rub either one of them

/*
Input height = {30, 10, 60, 10, 60};

Output: 120 [60+60]
*/

// 1. Recursion
//TC: O(2^n)
//      2 choices Pick and Notpick available in each ietartion. So 2^n complexity for n elements
//SC: O(n)      [Recursive stack space]
int maxSum(int index, vector<int>& arr)
{
    if(index == 0)
    {
        return arr[index];
    }

    if(index < 0)
    {
        return 0;
    }

    int pickCurr = arr[index] + maxSum(index-2, arr);

    int notPickCurr = maxSum(index-1, arr);

    return max(pickCurr, notPickCurr);
}

//2. Memoization
//TC: O(N)
//      Only the left side of recusrsion will be executed.
//      For right side ie.e the overlappting sub problem vale will be taken from dp, so O(1)
//SC: O(N) + O(N)
//      O(N) for recursive stack space
//      O(N) for dp data structure
int maxSumM(int index, vector<int>& arr, vector<int>& dp)
{
    if(index == 0)
    {
        return arr[index];
    }

    if(index < 0)
    {
        return 0;
    }

    if(dp[index] != -1)
    {
        return dp[index];
    }

    int pickCurr = arr[index] + maxSumM(index-2, arr, dp);

    int notPickCurr = maxSumM(index-1, arr, dp);

    return dp[index] = max(pickCurr, notPickCurr);
}

//3. Tabulation
//TC: O(N)
//      For loop till index N
//SC: O(N)  [for dp vector]
int maxSumT(int index, vector<int>& arr, vector<int>& dp)
{
    dp[0] = arr[0];

    for(int i = 1; i < index; i++)
    {
       int pickCurr = arr[i];
       if(i > 1)
           pickCurr += dp[i-2];

       int notPickCurr = dp[i-1];

       dp[i] = max(pickCurr, notPickCurr);
    }

    return dp[index-1];
}

//3. Tabulation with space optimization
//TC: O(N)
//      For loop till index N
//SC: O(1)  [No extra space required]
int maxSumTO(int index, vector<int>& arr)
{
    int prev1 = arr[0];
    int prev2 = 0;

    for(int i = 1; i < index; i++)
    {
       int pickCurr = arr[i];
       if(i > 1)
           pickCurr += prev2;

       int notPickCurr = prev1;

       int curr = max(pickCurr, notPickCurr);

       prev2 = prev1;
       prev1 = curr;
    }

    return prev1;
}

void houseRobber(vector<int>& input)
{
    int n = input.size();

    vector<int> temp1; //Includes 1st house and excludes last house
    vector<int> temp2; //Includes last house and excludes 1st house

    for(int i = 0; i < n; i++)
    {
        if(i != n-1)
            temp1.push_back(input[i]);

        if(i != 0)
            temp2.push_back(input[i]);

    }

    //Recursive
    int r1 = maxSum(temp1.size()-1, temp1);
    int r2 = maxSum(temp2.size()-1, temp2);
    cout<<"Max Rubbed (R) = "<<max(r1, r2)<<endl;

    //Note: Using dpm1,dpm2, dpt1, dpt2 just to ensure that they dont contains value from previous function call
    //as all use cases are implemented in one program. May not be the case in actual program.

    //Memoization
    vector<int> dpm1(temp1.size(), -1);
    r1 = maxSumM(temp1.size()-1, temp1, dpm1);
    vector<int> dpm2(temp2.size(), -1);
    r2 = maxSumM(temp2.size()-1, temp2, dpm2);
    cout<<"Max Rubbed (M) = "<<max(r1, r2)<<endl;

    //Tabulation
    vector<int> dpt1(temp1.size(), -1);
    r1 = maxSumT(temp1.size(), temp1, dpt1);
    vector<int> dpt2(temp2.size(), -1);
    r2 = maxSumT(temp2.size(), temp2, dpt2);
    cout<<"Max Rubbed (T) = "<<max(r1, r2)<<endl;

    //Tabulation space optimized
    r1 = maxSumTO(temp1.size(), temp1);
    r2 = maxSumTO(temp2.size(), temp2);
    cout<<"Max Rubbed (TO)= "<<max(r1, r2)<<endl;
}

int main()
{
    vector<int> input{30, 10, 60, 10, 60};

    houseRobber(input);

    return 0;
}
