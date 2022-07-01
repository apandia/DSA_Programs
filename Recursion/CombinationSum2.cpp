#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Find list of unique combination whose sum equals target.
// A number may be chosen only one time and  ig 2,6 are addded the 6,2 should not be added for target 8.

// Input array: [10,1,2,7,6,1,5]
// target = 8

/*
Output:
[1,1,6],
[1,2,5],
[1,7],
[2,6]
*/

//Brute Force
//TC: O(2^n * (klog k + klog k))
//SC: O(k*x)     [k = average length, x = no. of combinations]
void findCombinationBF(int index, int target, vector<int>& input, set<vector<int>>& ans, vector<int>& ds) {
    //Base case
    if(index == input.size()){
        if(target == 0){
            //Sorting is required to prevent insertion of [7,1] to ans when [1,7] is already inserted
            sort(ds.begin(), ds.end());     //TC: klog k    [sorting vector of k size]
            ans.insert(ds);                 //TC: klog k    [inserting k elements to set]
        }
        return;
    }

    //recursion case
    //Pick same index
    if(input[index] <= target){
        ds.push_back(input[index]);
        findCombinationBF(index+1, target-input[index], input, ans, ds);
        ds.pop_back();
    }

    //move to next index
    findCombinationBF(index+1, target, input, ans, ds);
}


set<vector<int>> combinationSumBF(vector<int>& candidates, int target) {
    set<vector<int>> ans;
    vector<int> ds;

    findCombinationBF(0, target, candidates, ans, ds);

    return ans;
}

//Optimized solution
//TC: O(2^n * k)      [k for push_bak operation to ans vector]
//SC: O(k*x)          [k elements in each combination with x such combination]
void findCombination(int index, int target, vector<int>& input, vector<vector<int>>& ans, vector<int>& ds)
{
    if(target == 0){
        ans.push_back(ds);
        return;
    }


    for(int i = index; i< input.size(); i++)
    {
        if((i > index) && (input[i] == input[i-1]))
            continue;

        if(input[index] > target)
            break;

        ds.push_back(input[i]);
        findCombination(i+1, target-input[i], input, ans, ds);
        ds.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> ds;

    findCombination(0, target, candidates, ans, ds);

    return ans;
}

int main()
{
    vector<int> v{10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> ans = combinationSum(v, target);

    cout << "Combinations are: " << endl;
    for (auto it : ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
}
