#include <iostream>
#include <vector>

using namespace std;

//TC: O(2^t * k) [t = target, k = average length]
//For a target of 10, there can be 10 possible choices to either pic or not pick
//SC: O(k*x)     [k = average length, x = no. of combinations]
class Solution {
    public:

    void findCombination(int index, int target, vector<int>& input, vector<vector<int>>& ans, vector<int>& ds) {
        //Base case
        if(index == input.size()){
            if(target == 0){
                ans.push_back(ds);
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
