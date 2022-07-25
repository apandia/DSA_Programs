#include <iostream>
#include <vector>

using namespace std;

// Find max sum of elements where no adjacent element can be picked

/*
Input height = {30, 10, 60, 10, 60, 50};

Output: 150 [30+60+60]
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

int main()
{
    //vector<int> input{30, 10, 60, 10, 60, 50};
    vector<int> input{2,1,4,9};

    //Recursive
    cout<<"Max sum (R) = "<<maxSum(input.size()-1, input)<<endl;

    //Memoization
    vector<int> dpm(input.size(), -1);
    cout<<"Max sum (M) = "<<maxSumM(input.size()-1, input, dpm)<<endl;

    //Tabulation
    vector<int> dpt(input.size(), -1);
    cout<<"Max sum (T) = "<<maxSumT(input.size(), input, dpt)<<endl;

    //Tabulation space optimized
    cout<<"Max sum (TO)= "<<maxSumTO(input.size(), input)<<endl;
}
