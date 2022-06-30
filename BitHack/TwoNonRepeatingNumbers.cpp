#include <iostream>
#include <vector>

using namespace std;

void findNonRepeatingNumbers(vector<int> arr)
{
	int xorValue = 0;

	//fnd the xor for all elements
	for (int i = 0; i < arr.size(); i++)
	{
		xorValue ^= arr[i];
	}

	//Get the rightmost set bit
	int rmsb = (xorValue) & ~(xorValue - 1);
	int x = 0;
	int y = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] & rmsb)
		{
			x ^= arr[i];			 
		}
		else
		{
			y ^= arr[i];
		}
	}

	cout << "Two non repeating numbers are = " << x << " , " << y << endl;

}

int main()
{
	vector<int> array{2, 4, 7, 9, 2, 4};

	findNonRepeatingNumbers(array);
}