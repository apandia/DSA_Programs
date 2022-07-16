#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int num)
{
	int start = 0;
	int end = arr.size() - 1;

	while (start <= end)
	{
		int mid = (start + end)/2;

		if (arr[mid] == num)
		{
			return mid;
		}
		if (arr[mid] > num)
		{
			end = mid -1;
		}
		else
		{
			start = mid + 1;
		}
	}

	return -1;
}

int main()
{
	vector<int> arr{ 5, 6, 7, 9, 11, 12, 13 };

	int num;
	cout << "Enetr the number to search: ";
	cin >> num;

	int index = binarySearch(arr, num);

	if(index != -1)
	{
		cout << "Number is Found and Index of number is: " << index << endl;
	}
	else
	{
		cout << "Number is Not Found" << endl;
	}

	return 0;
}
