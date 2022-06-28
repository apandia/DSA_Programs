#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// Find the next greater element of element in array1 based on array2
// Note: array1 is subarray of array2

// Input Array1 = [4,1,2]
// Input Array2 = [1,3,4,2]
//         nge2 = [3,4,-1,-1]

// Output Array = [-1,3,-1]
// nge[4] = -1      [no element present in right of 4 in array2 which is grater than 4]
// nge[1] = 3       [next greater element of 1 in right side of array2 is 3]
// nge[2] = -1      [no element present in right of 4 in array2 which is grater than 4]

//Approach:
//1. create the nge vector for array2 and store number and nge in an unorder map
//   um[num] = nge
//2. iterate over array1, check if the number present in unorder map and if yes get the nge.
//Note: Circular nge approach is not required here

//TC: O(N)
//SC: O(N)      [Extra O(N) space used for unorder map but overall SC will be O(N)]
// For detail complexity analysis refer:
// https://github.com/apandia/DSA_Programs/blob/main/Arrays/NextGreaterElement.cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> nge;
    stack<int> st;
    unordered_map<int, int> numNgeMap;

    for(int i = nums2.size()-1; i >=0; i--)
    {
        while(!st.empty() && (st.top() < nums2[i]))
        {
            st.pop();
        }

        if(!st.empty())
        {
            numNgeMap[nums2[i]] = st.top();
        }

        st.push(nums2[i]);
    }

    for(int num : nums1)
    {
        if(numNgeMap.count(num))
            nge.push_back(numNgeMap[num]);
        else
            nge.push_back(-1);
    }

    return nge;
}

int main()
{
    vector<int> arr1 = {4,1,2};
    vector<int> arr2 = {1,3,4,2};

    cout<<"Array1 = ";
    for(int val : arr1)
        cout<<val<< " ";
    cout<<endl;

    cout<<"Array2 = ";
    for(int val : arr2)
        cout<<val<< " ";
    cout<<endl;

    vector<int> nge = nextGreaterElement(arr1, arr2);

    cout<<"Next greater element array = ";
    for(int val : nge)
        cout<<val<< " ";
    cout<<endl;

    return 0;
}
