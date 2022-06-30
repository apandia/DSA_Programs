#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int longestBand(vector<int> array)
{
	int n = array.size();
	unordered_set<int> s;

	for (int x : array)
	{
		s.insert(x);
	}

	int longest = 1;

	for (auto elem : s)
	{
		int prev = elem - 1;
		
		if (s.find(prev) == s.end())
		{
			int count = 1;
			int next = elem + 1;

			while (s.find(next) != s.end())
			{
				count++;
				next++;
			}

			longest = max(longest, count);
		}
	}

	return longest;
}

int main()
{
	vector<int> arr = { 1,9,3,0,18,5,2,4,10,7,12,6 };
	cout << "LongestBand = " << longestBand(arr) << endl;

	return 0;
}