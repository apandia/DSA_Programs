#include <iostream>
#include <vector>

using namespace std;

// Print all subsequences of given array

//Input array: [1,2,3]
/*
Output:
[1,2,3]
[1,2]
[1,3]
[1]
[2,3]
[2]
[3]
[]
*/

// Approach1: Using bit method (Power Set)
//TC: O(2^n * n)    [2^n for outer loop and n for inner loop]
//SC: O(1)
void printAllSubsequencePowerSet(vector<int>& array)
{
    int n = array.size();

    for(int num = 0; num < (1<<n); num++) //run the for loop 2^n times
    {
        cout<<"[";
        for(int i = 0; i < n; i++)
        {
            if(num & (1<<i))
            {
                cout<<array[i];
            }
        }
        cout<<"]"<<endl;
    }
}

// Approach2: Using Recursion
// TC: O(2^n)
// [2^n * n if we consider the for loop to print ds.
// Note ds does not always print n element so the complexity of for loop is ~n]
// SC: O(1)     [Not considering recursive stack space]
void printAllSubsequence(int index, vector<int>& array, vector<int>& ds)
{
    if(index == array.size())
    {
        cout<<"[";
        for(int n : ds)
        {
            cout<<n;
        }
        cout<<"]"<<endl;
        return;
    }

    ds.push_back(array[index]);
    printAllSubsequence(index+1, array, ds);

    ds.pop_back();
    printAllSubsequence(index+1, array, ds);
}

int main()
{
    vector<int> input = {1,2,3};

    printAllSubsequencePowerSet(input);
    cout<<endl;

    vector<int> ds;
    printAllSubsequence(0, input, ds);

    return 0;
}
