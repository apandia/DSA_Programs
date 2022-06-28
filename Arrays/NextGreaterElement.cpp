#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Find the next greater element

// Input Array = [3,10,4,2,1,2,6,1,7,2,9]

// Output Array = [10,-1,6,6,2,6,7,7,9,9,-1]        [If circular approach is not condidered]
// Output Array = [10,-1,6,6,2,6,7,7,9,9,10]        [If circular approach is condidered]

//TC: O(2n + 2n) = ~O(n)
// Outer loop runs for 2n-1 so ~O(2n)
// Inner loop runs for 2n times for the entire program i.e. during entire 2n execution of outer for loop
// the inner for loop will run for 2n times. for each ieration of outer for loop inner for loop will not run
// for 2n times. sometimes 1, sometimes 2 times etc ...
// So the resultant TC is 2n+2n and not 2n*2n

//SC: O(n)      [for stack and not considering result vector]
vector<int> nextGreaterElement(vector<int>& arr)
{
    int n = arr.size();

    vector<int> result(n,-1);
    stack<int> st;

    for(int i = n-1; i >= 0; i--)
    {
        while(!st.empty() && (st.top() <= arr[i]))
        {
            st.pop();
        }

        if(!st.empty())
        {
            result[i] = st.top();
        }

        st.push(arr[i]);
    }

    return result;
}

//Circular Approach
//1. Create imaginary array with input array i.e 0 -> n [-> 0 ->n]
//2. Use modulo to get index location, i.e even if the index is 6, since 6%5 is 1, it will pick element from index 1
//3. While adding element to result vector,put check for (i < n) so that result array contains result upto index n-1
//   and not upto 2n-1 which is imaginary array
vector<int> nextGreaterElementCircular(vector<int>& arr)
{
    int n = arr.size();

    vector<int> result(n,-1);
    stack<int> st;

    for(int i = 2*n-1 ; i >= 0; i--)
    {
        while(!st.empty() && (st.top() <= arr[i%n])) //Use of modulo
        {
            st.pop();
        }

        if(i < n) //Additional check to store the result only for first n elements
        {
            if(!st.empty())
            {
                result[i] = st.top();
            }
        }

        st.push(arr[i%n]);
    }

    return result;
}

int main()
{
    vector<int> arr = {3,10,4,2,1,2,6,1,7,2,9};

    cout<<"Array = ";
    for(int val : arr)
        cout<<val<< " ";
    cout<<endl;

    vector<int> nge = nextGreaterElement(arr);

    cout<<"Next greater element array = ";
    for(int val : nge)
        cout<<val<< " ";
    cout<<endl;

    vector<int> ngec = nextGreaterElementCircular(arr);

    cout<<"Next greater element array(circular) = ";
    for(int val : ngec)
        cout<<val<< " ";
    cout<<endl;

    return 0;
}
