#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Print all unique subsets of array (array may contains duplicate entries

//Input array: [1,2,2]
/*
Output:
[1,2,2]
[1,2]
[1,2]   X->not allowed, [1,2] already present
[1]
[2,2]
[2]
[2]     X-> not allowed, [2] is already present
[]

SO the output should be:
[1,2,2]
[1,2]
[1]
[2,2]
[2]
[]

Note: Output subsets order is not important
*/

// TC: O(2^n + m log m)     [m logm TC to add elements inside set from vector. m = 2^n as vector contains 2^n subsets]
// SC: O(2^n + 2^n) ~O(2^n) [SC for vector and set. not considering recursive stack space]
void uniqueSubsets(int index, vector<int>& array, vector<int>& ds, set<vector<int>>& subsets)
{
    if(index == array.size())
    {
        subsets.insert(ds);
        return;
    }

    ds.push_back(array[index]);
    uniqueSubsets(index+1, array, ds, subsets);

    ds.pop_back();
    uniqueSubsets(index+1, array, ds, subsets);
}

vector<vector<int>> uniqueSubsequence(vector<int>& array)
{
    vector<vector<int>> result;

    vector<int> ds; //to hold a subset
    set<vector<int>> s; // to hold unique subsets

    uniqueSubsets(0, array, ds, s);

    for(auto it : s)
    {
        result.push_back(it);
    }

    return result;
}


//Optimized solution
//TC: O(2^n * n)
// 2^n: there will ne 2^n subsets so 2^n recursion and
// n  : assuming average length of each subsets as n, O(n) TC to add ds to ans

//SC: O(2^n * n)
//  2^n: num subsets to store
//  n  : avg length of each subset

//Auxlary Space: O(n)   [For recursion]

//Note: Base case is not required as the for loop will ensure that the function is executed nums.size()-1 times only
void findSubsets(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds)
{
    ans.push_back(ds); //O(n) TC Operation as average length of each subset is n

    for(int i = index; i< nums.size(); i++)
    {
        if((i > index) && (nums[i] == nums[i-1]))
            continue;

        ds.push_back(nums[i]);
        findSubsets(i+1, nums, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> ds;

    //Sort the array so that 2 consecutive same value can be compared
    sort(nums.begin(), nums.end());

    findSubsets(0, nums, ans, ds);

    return ans;
}

int main()
{
    vector<int> input = {1,2,2};

    vector<vector<int>> result = subsetsWithDup(input);
    for(auto it : result)
    {
        cout<<"[";
        for(auto it1 : it)
        {
            cout<<it1;
        }
        cout<<"]"<<endl;
    }

    return 0;
}
