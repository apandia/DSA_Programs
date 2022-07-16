#include <iostream>
#include <vector>

using namespace std;

int partitionWithPivotAsFirstElement(vector<int>& arr, int start, int end)
{
	int pivot = arr[start];
	int i = start + 1;

	for (int j = start+1; j <= end; j++)
	{
		if (arr[j] < pivot)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}

	swap(arr[start], arr[i - 1]);

	return (i - 1);
}

int partitionWithPivotAsLastElement(vector<int>& arr, int start, int end)
{
	int pivot = arr[end];
	int i = start-1;

	for (int j = start; j < end; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[end]);
	
	return (i + 1);
}

void quickSort(vector<int>& arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	//Use either of the function call to set Pivot element as first or last element
	//int p = partitionWithPivotAsLastElement(arr, start, end);
	int p = partitionWithPivotAsFirstElement(arr, start, end);

	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

int main()
{
	vector<int> arr{ 12, 5, 9, 11, 13, 5, 6, 7 };

	quickSort(arr, 0, arr.size() - 1);

	cout << "Array after Quick Sort: " << endl;
	for (int num : arr)
		cout << num << ",";

	return 0;
}
