#include <iostream>

using namespace std;

//Complexity id theta(log n)
int countSetBits(int n)
{
	int count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}

	return count;
}

//Brian kernigham algorithm O(log n)
int countSetBitsBK(int n)
{
	int temp = n;

	int count = 0;
	while (n)
	{
		n &= (n - 1);
		count++;
	}

	int c1 = 0;
	while (temp)
	{
		int rsbm = temp & ~temp;
		temp -= rsbm;
		c1++;
	}

	return count;
}

int main()
{
	int i = 13;

	cout << "\nNumber of Set Bits = " << countSetBits(i);
	cout << "\nBK Number of Set Bits = " << countSetBitsBK(i);

	return 0;
}