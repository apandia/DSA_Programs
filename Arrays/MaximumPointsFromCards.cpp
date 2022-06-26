#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Find maximum points by selecting k cards from pack of cards.
// You are allowed to choose either from front or end.

// Input Array = [1,2,3,4,5,6,1]
// Max value = 12 [5,6,1]

// Input Array = [10,2,3,4,5,6,1]
// Max value = 17 [10,6,1]

//TC: O(n)
//SC: O(1)
int maxScore(vector<int>& cardPoints, int k)
{
    int totalSum = 0;
    int n = cardPoints.size();

    for(int val : cardPoints)
        totalSum += val;

    if(n == k)
        return totalSum;

    int notPickCount = n-k;

    int currWindowSum = 0;
    //Find min sum for the window of size not pick count
    for(int i = 0; i < notPickCount; i++)
        currWindowSum += cardPoints[i];

    //Now find the min sum among all window of size notPickCOunt using sliding window technique
    int minWindowSum = currWindowSum;
    for(int i = notPickCount; i < n ; i++)
    {
        currWindowSum += cardPoints[i] - cardPoints[i-notPickCount];
        minWindowSum = min(minWindowSum, currWindowSum);
    }

    return totalSum - minWindowSum;
}

int main()
{
    vector<int> arr1 = {1,2,3,4,5,6,1};
    vector<int> arr2 = {10,2,3,4,5,6,1};

    cout<<"Array1 = ";
    for(int val : arr1)
        cout<<val<< " ";
    cout<<endl;

    int k = 3;
    cout<<"Max points by selecting "<<k<<" cards = "<<maxScore(arr1, k);

    cout<<endl;

    cout<<"Array2 = ";
    for(int val : arr2)
        cout<<val<< " ";
    cout<<endl;

    cout<<"Max points by selecting "<<k<<" cards = "<<maxScore(arr2, k);

    cout<<endl;

    return 0;
}
