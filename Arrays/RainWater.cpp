#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int rainWater(vector<int> arr)
{
	int n = arr.size();
	if (n <= 2)
		return 0;

	//initialize and left and right vector with 0
	vector<int> left(n, 0);
	vector<int> right(n, 0);

	int totalWater = 0;

	//set left vector to first element of array
	left[0] = arr[0];

	//set right vector to last element of array
	right[n - 1] = arr[n - 1];

	
	for (int i = 1; i < n; i++)
	{
		left[i] = max(left[i-1], arr[i]);
		right[n-i-1] = max(right[n - i], arr[n - i - 1]);
	}

	for (int i = 0; i < n; i++)
	{
		totalWater += min(left[i], right[i]) - arr[i];
	}

	return totalWater;
}

int main()
{
	vector<int> arr = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << "Rain Water = " << rainWater(arr) << endl;

	return 0;
}