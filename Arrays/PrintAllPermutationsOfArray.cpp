#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Print all permutaions of given array

//Input array: [1,2,3]
/*
Output:
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
*/

//TC: O(n! * n)
//      O(n!) = n! permutations are generated for n
//      O(n)  = for loop with n iterations
//SC: O(n) + O(n)
//      O(n)  = for ds vector
//      O(n)  = for visited array
void findPermutation(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, vector<int>& visited)
{
    if(ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(!visited[i])
        {
            ds.push_back(nums[i]);
            visited[i] = 1;
            findPermutation(nums, ans, ds, visited);
            ds.pop_back();
            visited[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> visited(nums.size(), 0);

    findPermutation(nums, ans, ds, visited);

    return ans;
}

// Otimzed implementation - space optimization
//TC: O(n! * n)
//SC: O(1)
void findPermutation(int index, vector<int>& nums, vector<vector<int>>& ans)
{
    if(index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        findPermutation(index+1, nums, ans);
        swap(nums[index], nums[i]); //reswap, backtracking to make the array as riginal one
    }

}

vector<vector<int>> permutation(vector<int>& nums)
{
    vector<vector<int>> ans;

    findPermutation(0, nums, ans);

    return ans;
}

int main()
{
    vector<int> input = {1,2,3};

    //vector<vector<int>> result = permute(input);
    vector<vector<int>> result = permutation(input); //call to optimized function
    for(auto it : result)
    {
        for(auto it1: it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }

    return 0;
}
