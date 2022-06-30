#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mountain(vector<int> a)
{
	int size = a.size();
	int largest = 0;

	for (int i = 1; i < size-2; i++)
	{
		//identify peaks. check a[i] is peak or not
		if ((a[i] > a[i - 1]) && (a[i] > a[i + 1]))
		{
			int count = 1;
			int j = i;

			//traverse left side
			while ((j > 1) && (a[j] > a[j - 1]))
			{
				count++;
				j--;
			}

			//move forward direction
			while ((i < size - 2) && (a[i] > a[i + 1]))
			{
				count++;
				i++;
			}

			largest = max(largest, count);
		}
	}

	return largest;
}

int main()
{
	vector<int> arr = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

	int count = mountain(arr);

	cout << count << endl;

	return 0;
}