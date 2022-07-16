#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &arr, int start, int end)
{
	int i = start;
	int mid = (start + end) / 2;
	int j = mid + 1;

	int count = 0;
	vector<int> temp;

	while ((i <= mid) && (j <= end))
	{
		if (arr[i] < arr[j])
		{
			temp.push_back(arr[i]);
			i++;
		}
		else
		{
			temp.push_back(arr[j]);
			j++;
			count += (mid - i + 1);
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

	//copy to main array from temp array
	int k = 0;
	for (int index = start; index <= end; index++)
	{
		arr[index] = temp[k];
		k++;
	}

	return count;
}

int inversionCount(vector<int> &arr, int start, int end)
{
	if (start >= end) {
		return 0;
	}

	int mid = (start + end) / 2;
	int cl = inversionCount(arr, start, mid);
	int cr = inversionCount(arr, mid + 1, end);

	int cm = merge(arr, start, end);

	return (cl + cr + cm);
}

int main()
{
	vector<int> arr{ 12, 5, 9, 11, 13, 5, 6, 7 };

	cout<<"Number of InversionCoount = "<< inversionCount(arr, 0, arr.size() - 1);

	return 0;
}
