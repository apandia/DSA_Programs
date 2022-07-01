#include <iostream>
#include <vector>

using namespace std;

// Print all subsequences with sum as k

//Input array: [1,2,3]
//Sum = 3
/*
Output:
All subsequences with sum 3 =
1 2
3
*/

// TC: O(2^n)
// [2^n * n if we consider the for loop to print ds.
// Note ds does not always print n element so the complexity of for loop is ~n]
// SC: O(1)     [Not considering recursive stack space]
void printAllSubsequence(int index, vector<int>& array, vector<int>& ds, int k, int sum)
{
    if(index == array.size())
    {
        if(sum == k)
        {
            for(int n : ds)
            {
                cout<<n<<" ";
            }
            cout<<endl;
        }
        return;
    }

    ds.push_back(array[index]);
    sum += array[index];
    printAllSubsequence(index+1, array, ds, k, sum);

    ds.pop_back();
    sum -= array[index];
    printAllSubsequence(index+1, array, ds, k, sum);
}

int main()
{
    vector<int> input = {1,2,3};

    int k = 3;
    vector<int> ds;
    cout<<"All subsequences with sum "<<k<<" = "<<endl;
    printAllSubsequence(0, input, ds, k, 0);

    return 0;
}
