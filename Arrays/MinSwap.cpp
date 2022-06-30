#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countMinSwap(vector<int> arr)
{
	int minSwap = 0;

	int n = arr.size();
	vector< pair<int, int> > ap;

	for (int i = 0; i < n; i++)
	{
		ap.push_back(make_pair(arr[i], i));
	}

	sort(ap.begin(), ap.end());

	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++)
	{
		//if the element is already visited or in correct position, do nothing
		int currentPos = i;
		int lastPosition = ap[i].second;
		if ((visited[i] == true) || (lastPosition == currentPos))
		{
			continue;
		}

		//visiting the element for first time
		//find any cycle is available for the element
		int cycle = 0;

		while (!visited[currentPos])
		{
			visited[currentPos] = true;
			currentPos = ap[currentPos].second;
			cycle++;
		}

		minSwap += (cycle - 1);
	}

	return minSwap;
}

int main()
{
	//vector<int> arr = { 5,4,3,2,1};
	vector<int> arr = {10,11,5,4,3,2,1};
	cout << countMinSwap(arr) << endl;

	return 0;
}