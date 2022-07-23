#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Find the Kth permutation where:N = sequence of numbers [1 .... N]

/*
Input:
N = 3, K = 3

All permutation(sorted) of sequence of N are:
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]

Output:
The Kth(3rd) permutation = [2,1,3]

*/
//TC: O(N^2)
//      O(N): for  placing N numbers in N positions
//      O(N): for each number we are reducing search space (to find next factorial value) by removing the element in previous step.
//            If there are N numbers then there will be ~N removal also.
//SC: O(N)
//      O(N): for numbers vector
string getPermutation(int n, int k)
{
    //Fill the array with numbers till n and find (n-1) factorial
    vector<int> numbers;
    int fact = 1;
    for(int i = 1; i < n; i++)
    {
        numbers.push_back(i);
        fact *= i;
    }
    numbers.push_back(n);

    string result = "";

    k = k-1; //To make k work with 0 based indexing of vector

    while(true)
    {
        result = result + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + k/fact);

        if(numbers.size() == 0)
        {
            break;
        }

        k = k % fact;
        fact = fact/numbers.size();
    }

    return result;
}

int main()
{
    int n = 3, k = 3;

    cout << "The Kth ("<<k<<") permutation = [" << getPermutation(n, k) << "]"<<endl;

    return 0;
}
