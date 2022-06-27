#include <iostream>
#include <string>

using namespace std;

// Print all subsequences of a string
/*
Input string = "abc"
All possible substring of abc =
        --> empty substring
a
b
ab
c
ac
bc
abc
*/

// Approach1: Using bit method (Power Set)
//TC: O(2^n * n)    [2^n for outer loop and n for inner loop]
//SC: O(1)
void printAllSubsequencePowerSet(string str)
{
    int n = str.size();

    for(int num = 0; num < (1<<n); num++)
    {
        string substring;

        for(int i = 0; i < n; i++)
        {
            if(num & (1<<i))
                substring += str[i];
        }
        cout<<substring<<endl;
    }
}

void printAllSubsequence(string str, int index, string& substring)
{
    if(index == str.length())
    {
        cout<<"{"<<substring<<"}"<<endl;
        return;
    }

    substring += str[index];
    printAllSubsequence(str, index+1, substring);
    substring.pop_back();
    printAllSubsequence(str, index+1, substring);
}

// Approach2: Using recursion

int main()
{
    string str = "abc";

    cout<<"All possible substring of "<<str<<" = "<<endl;

    printAllSubsequencePowerSet(str);

    cout<<"All possible substring of "<<str<<" = "<<endl;

    string tmp;
    printAllSubsequence(str, 0, tmp);

    return 0;
}
