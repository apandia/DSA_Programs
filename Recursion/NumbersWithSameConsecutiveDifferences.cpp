#include <iostream>
#include <vector>

using namespace std;

// Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k

/*
Input: n = 3, k = 7
Output: [181,292,707,818,929]
 */

//TC: O(n⋅2^n)      [for next = prev+k and prev-k, run the dfs for n-1 times]
//SC: O(2^n)        [Auxilary stack space not considering result vector]
void  dfs(int n, int k, int curr, vector<int>& result)
{
    if(n == 0)
    {
        result.push_back(curr);
        return;
    }

    int prev = curr % 10;

    for (const int next : {prev - k, prev + k})
    {
        if (0 <= next && next <= 9)
            dfs(n - 1, k, curr * 10 + next, result);
    }
}

vector<int> numsSameConsecDiff(int n, int k)
{
    if(n == 1)
        return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> result;

    if (k == 0)
    {
        for (char c = '1'; c <= '9'; ++c)
        {
            result.push_back(stoi(string(n, c)));
        }

        return result;
    }

    //Else there will be duplicate answers for k = 0
    //111 111 111 111 222 222 222 222 333 333 333 333 444 444 444 444
    //555 555 555 555 666 666 666 666 777 777 777 777 888 888 888 888 999 999 999 999

    for(int i = 1; i <= 9; i++)
    {
        dfs(n-1, k, i, result);
    }

    return result;
}

int main()
{
    int n = 3;
    int k = 7;

    vector<int> result = numsSameConsecDiff(n, k);
    for(auto value : result)
    {
        cout<<value<<" ";
    }
    cout<<endl;

    return 0;
}
