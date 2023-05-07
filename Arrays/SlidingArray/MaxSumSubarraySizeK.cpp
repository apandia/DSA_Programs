#include <iostream>
#include <vector>

using namespace std;

/*
Input : { 2, 5, 1, 8, 2, 9, 1}
Window (k) = 3
Output : 19 (8, 2, 9)
*/

//Time complexity : O(N)
int maxSum(vector<int>& input, int k)
{
    if (k > input.size())
        return -1;

    int maxSum = 0;
    //Find the sum of first k element
    for (int i = 0; i < k; i++)
    {
        maxSum += input[i];
    }

    int windowSum = maxSum;
    for (int i = k; i < input.size();i++)
    {
        windowSum = windowSum + input[i] - input[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main()
{
    vector<int> input = { 2, 5, 1, 8, 2, 9, 1 };

    int k = 3;

    cout << "Maximum sum in window of " << k << " is = " << maxSum(input, k) << endl;

    return 0;
}
