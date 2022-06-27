#include <iostream>
#include <string>

using namespace std;

//Find minimum deci-binary number required to get a sum S

/*
Input: S = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32

Input: S = “82734”
Output: 8
Explanation: S can be represented as sum minimum of 8 Deci-Binary numbers {11111, 11111, 10111, 10101, 10100, 10100, 10100, 10000}.
*/

/* Appraoch:
 * 1. Each deci-binary number can only contain 0 or 1
 * 2. To get a number n, we will ideally need n numbers of 1.
 * 3. With point#2 in consideration, we will need numbers of 1s equal to max interger value in the tring.
 *    In string1, max int value is 3, so we will need 3 deci-binary with 1 at 0th position (index starts at 0 from left)
 *    In string2, max int value is 8, so we will need 8 deci-binary with 1 at 0th position (index starts at 0 from left)
 * 4. If the string is 27348, max int valiue is 8, so we will need 8 deci-binary with 1 at 4th position (index starts at 0 from left)
*/

//TC: O(N)
//SX: O(1)
int minDeciBinaryNumberRequired(string str)
{
    int numRequired = 0;

    for(int i = 0; i < str.size(); i++)
    {
        numRequired = max(numRequired, str[i] - '0');
    }

    return numRequired;
}

int main()
{
    string str1 = "31";
    string str2 = "82734";
    string str3 = "27346209830709182346";

    cout<<"Min Deci-Binary required for "<<str1<<" = "<<minDeciBinaryNumberRequired(str1)<<endl;
    cout<<"Min Deci-Binary required for "<<str2<<" = "<<minDeciBinaryNumberRequired(str2)<<endl;
    cout<<"Min Deci-Binary required for "<<str3<<" = "<<minDeciBinaryNumberRequired(str3)<<endl;

    return 0;
}
