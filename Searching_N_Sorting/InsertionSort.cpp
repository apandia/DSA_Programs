#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int n)
{
	int temp, j;

	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		temp = arr[i];

		while ((j >= 0) && (arr[j] > temp))
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

int main()
{
	vector<int> arr{ 12, 5, 9, 11, 13, 5, 6, 7 };

	insertionSort(arr, arr.size());
	cout << "Array after Insertion Sort: " << endl;
	for (int num : arr)
		cout << num << ",";

	return 0;
}
