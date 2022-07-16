#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int start, int end)
{
	int i = start;
	int mid = (start + end) / 2;
	int j = mid + 1;

	vector<int> temp;

	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j]) {
			temp.push_back(arr[i]);
			i++;
		}
		else {
			temp.push_back(arr[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		temp.push_back(arr[i]);
		i++;
	}

	while (j <= end)
	{
		temp.push_back(arr[j]);
		j++;
	}

	int k = 0;
	for (int index = start; index <= end; index++)
	{
		arr[index] = temp[k];
		k++;
	}
}

void mergeSort(vector<int> &arr, int start, int end)
{
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	merge(arr, start, end);
}

int main()
{
	vector<int> arr{ 12, 5, 9, 11, 13, 5, 6, 7 };

	mergeSort(arr, 0, arr.size() - 1);
	for (int num : arr)
		cout << num << ",";
	
	return 0;
}
