#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Pallindrome Partitioning

/*
Input String: aabb

Output: All possible combination of substring that will form pallindrome
{a, a, b, b}
{a, a, bb}
{aa, b, b}
{aa, bb}
*/
bool checkPallindrom(string str, int start, int end)
{
    while(start <= end)
    {
        if(str[start] == str[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

void partitionString(int index, string str, vector<vector<string>>& ans, vector<string>& subset)
{
    if(index == str.size())
    {
        ans.push_back(subset);
        return;
    }

    for(int i = index; i < str.size(); i++)
    {
        if(checkPallindrom(str, index, i))
        {
            subset.push_back(str.substr(index, i-index+1));
            partitionString(i+1, str, ans, subset);
            subset.pop_back();
        }
    }
}

vector<vector<string>> getPallindromePartition(string str)
{
    vector<vector<string>> ans;
    vector<string> subset;

    partitionString(0, str, ans, subset);

    return ans;
}

int main()
{
    string str = "aabb";

    vector<vector<string>> result = getPallindromePartition(str);
    for(auto it : result)
    {
        cout<<"{";
        for(auto it1 : it)
        {
            cout<<it1<<" ";
        }
        cout<<"}"<<endl;
    }

    return 0;
}
