#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Find maximum value in a window of size k

//Input array = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [3,3,5,5,6,7]

/*
Window position                Max
-------------------------     -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

//Brute force implementation
//TC: O(N * K)
//SC: O(1)
vector<int> maxSlidingWindowBF(vector<int>& nums, int k)
{
    vector<int> result;
    int n = nums.size();

    for(int i = 0; i <= n-k; i++)
    {
        int maxValue = nums[i];
        for(int j = i; j <= i+k-1; j++)
        {
            maxValue = max(maxValue, nums[j]);
        }
        result.push_back(maxValue);
    }
    return result;
}

//Optimized implementation
//TC: O(N)
//SC: O(1)

/* Approach:
 * 1. Iterate over elements of array
 * 2. If any index is out of range for current window then discard that index from deque
 * 3. Check the indexes in deque from back and if the value at that index is smaller than
 *    value at current index pop them from deque
 * 4. Push the current index to deque
 * 5. Get the fromnt element from deque and push the value at that index to result
 *    (Note: Check if the current index is greater than or equal to k. Otherwise values of index
 *    like 0,1 will be push which is not correct when k =3)
 */
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> result;
    deque<int> dq;

    for(int i = 0; i < nums.size(); i++)
    {
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();

        while(!dq.empty() && (nums[dq.back()] < nums[i]))
            dq.pop_back();

        dq.push_back(i);

        if(i >= k-1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main()
{
    vector<int> arr = {1,3,-1,-3,5,3,6,7};

    cout<<"Array = ";
    for(int val : arr)
        cout<<val<< " ";
    cout<<endl;

    int k = 3;
    cout<<"Max value in each window of size [ "<<k<<" ] = ";

    vector<int> result = maxSlidingWindowBF(arr, k);

    for(int val : result)
        cout<<val<< " ";
    cout<<endl;

    cout<<"Max value in each window of size [ "<<k<<" ] = ";

    vector<int> result2 = maxSlidingWindow(arr, k);

    for(int val : result2)
        cout<<val<< " ";
    cout<<endl;

    return 0;
}
