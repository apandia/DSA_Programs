#include <iostream>
#include <vector>

using namespace std;

// Print sum of each subset of array

//Input array: [1,2,3]
/*
Output:
[1,2,3] --> 6
[1,2]   --> 3
[1,3]   --> 4
[1]     --> 1
[2,3]   --> 5
[2]     --> 2
[3]     --> 3
[]      --> 0
*/

// TC: O(2^n)
// SC: O(2^n)
void printSubsetSum(int index, vector<int>& array, vector<int>& ds, int subsetSum)
{
    if(index == array.size())
    {
        cout<<"[";
        for(int n : ds)
        {
            cout<<n;
        }
        cout<<"] --> "<<subsetSum<<endl;
        return;
    }

    ds.push_back(array[index]);
    printSubsetSum(index+1, array, ds, subsetSum+array[index]);

    ds.pop_back();
    printSubsetSum(index+1, array, ds, subsetSum);
}

int main()
{
    vector<int> input = {1,2,3};

    vector<int> ds;
    printSubsetSum(0, input, ds, 0);

    return 0;
}
