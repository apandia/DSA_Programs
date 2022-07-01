#include <iostream>
#include <vector>

using namespace std;

// Find list of unique combination whose sum equals target.
// A number may be chosen multiple times.

// Input array: [2,3,6,7]
// target = 7

/*
Output:
2, 2, 3     [2 is picked 2 times]
7
*/

//TC: O(2^t * k) [t = target, k = average length of combination]
//For a target of 10, there can be 10 possible choices to either pic or not pick and sometimes same index/value is picked multiple times.
//Consider array [1,2] and target to be 6, then 1 will be picked 6 times.
//SC: O(k*x)     [k = average length, x = no. of combinations]
class Solution {
    public:

    void findCombination(int index, int target, vector<int>& input, vector<vector<int>>& ans, vector<int>& ds) {
        //Base case
        if(index == input.size()){
            if(target == 0){
                ans.push_back(ds);  // say k elements are pushed to ans, the TC will be k*1=k, TC of push_back is O(1)
            }
            return;
        }

        //recursion case
        //Pick same index
        if(input[index] <= target){
            ds.push_back(input[index]);
            findCombination(index, target-input[index], input, ans, ds);
            ds.pop_back();
        }

        //move to next index
        findCombination(index+1, target, input, ans, ds);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, target, candidates, ans, ds);

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> v{2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = obj.combinationSum(v, target);

    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
