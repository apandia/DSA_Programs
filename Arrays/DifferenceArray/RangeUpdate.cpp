#include <iostream>
#include <vector>

using namespace std;

/*
Input : A [] { 10, 5, 20, 40 }
update(1, 3, 20)
Output : A [] { 10, 25, 40, 60 }
*/

// Time Complexity : O(N)
// Range update time complexity : O(1)
vector<int> updateRange(vector<int>& input, int l, int r, int val)
{
    int n = input.size();

    vector<int> arr(n + 1);

    arr[0] = input[0];
    arr[n] = 0;

    //Initialize difference array
    for (int i = 1; i < n; i++)
    {
        arr[i] = input[i] - input[i - 1];
    }

    //Range Update Rule : increase the values for element after index l and decrease the value of element after index r
    //arr[l] += val and arr[r+1] -= val

    arr[l] += val;
    arr[r + 1] -= val;

    //Update the array based on earlier calculated difference array
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }

    arr.pop_back();

    return arr;
}

int main()
{
    vector<int> input = { 10, 5, 20, 40 };

    vector<int> output = updateRange(input, 1, 3, 20);

    cout << "Output : ";
    for (auto val : output)
        cout << val << " ";

    cout << endl;

    return 0;
}
