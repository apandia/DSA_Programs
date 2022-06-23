#include <iostream>
#include <vector>

using namespace std;

// Find the maximum subarray sum

// Input Array = [-2,1,-3,4,-1,2,1,-5,4]

// Max subarray sum = 6     [4,-1,2,1]

//Brute Force - find each subset and sum of that subset
//TC: O(n ^ 2)
//SC: O(1)
/*int maxSubarray(vector<int>& arr)
{
    int maxSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++)
    {
        int currSubsetSum = 0;
        for(int j = i; j < arr.size(); j++)
        {
            currSubsetSum += arr[j];
            maxSum = max(maxSum, currSubsetSum);
            if(currSubsetSum < 0)
                currSubsetSum = 0;

        }
    }

    return maxiSum;
}*/

//TC: O(n)
//SC: O(1)
int maxSubarray(vector<int>& arr)
{
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<"Array = ";
    for(int val : arr)
        cout<<val<< " ";
    cout<<endl;

    cout<<"Max subarray sum = "<<maxSubarray(arr);

    cout<<endl;

    return 0;
}
