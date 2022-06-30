#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> subarrayIndex(vector<int> arr)
{
	int n = arr.size();
	if (n < 2)
		return{ -1,-1 };

	int smallest = INT_MAX;
	int largest = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		//check a number is out of order or not
		if ((i != 0) && (i != n - 1))
		{
			if ((arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1]))
			{
				smallest = min(smallest, arr[i]);
				largest = max(largest, arr[i]);
			}
		}
	}

	//next step find the right index where smallest and largest lie (subarray) for out solution
	if (smallest == INT_MAX) {
		return{ -1,-1 };
	}

	int left = 0;
	while (smallest >= arr[left]) {
		left++;
	}
	int right = arr.size() - 1;
	while (largest <= arr[right]) {
		right--;
	}

	return{ left,right };

}

int main()
{
	vector<int> arr = {1,2,3,4,5,8,6,7,9,10,11};
	vector<int> index = subarrayIndex(arr);
	cout << "Subarray index = [" << index[0] << ", " << index[1] << "]" << endl;
}