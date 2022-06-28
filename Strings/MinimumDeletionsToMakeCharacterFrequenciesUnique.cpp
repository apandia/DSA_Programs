#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Find Minimum Deletions to Make Character Frequencies Unique

/*
Input str = "aaabbbcc"
Output: 2

Explanation: Delete one 'b' and one 'c' resulting in the good string "aaabbc".
*/

/* Appraoch:
 * 1. Count frequencies of each character
 * 2. Sort the frequencies in decresing order
 * 3. Keep on decrementing the frequencies and ensure that frequencies are unique
 * 4. If the frequency after decrement becomes 0 at some point, then delete all character after that
*/

//TC: O(N)          [Itertaing over all characters in string to get the frequency of each character]
//                  [TC of sorting frequncy vector is constnat as it is of fixed size]
//SX: O(1) / O(26)  [Vector is of constact size 26]
int minDeletions(string str)
{
    vector<int> frequency(26);

    for(auto c : str)
    {
        frequency[c-'a']++;
    }

    //Sort frequency in decreasing order
    sort(frequency.begin(), frequency.end(), greater<int>());

    int currFrequency = frequency[0];

    int result = 0;

    for(auto freq : frequency)
    {
        //deletion case
        if(freq > currFrequency)
        {
            if(currFrequency > 0)
                result += freq-currFrequency;
            else
                result += freq;
        }

        currFrequency = min(currFrequency-1, freq-1); //case where freq[i]=9, freq[i+1]=4 (not 8)
    }
    return result;
}

int main()
{
    string str1 = "aab";
    string str2 = "aaabbbcc";
    string str3 = "ceabaacb";

    cout<<"Minimum Deletions To Make Character Frequencies Unique ["<<str1<<"] = "<<minDeletions(str1)<<endl;
    cout<<"Minimum Deletions To Make Character Frequencies Unique ["<<str2<<"] = "<<minDeletions(str2)<<endl;
    cout<<"Minimum Deletions To Make Character Frequencies Unique ["<<str3<<"] = "<<minDeletions(str3)<<endl;

    return 0;
}
