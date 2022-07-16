#include <iostream>

using namespace std;

//Iterate and count.Complexity id theta(log n)
//All integers can be represented in 32 bits. so max iteration will be 32 for 2^32 elelemnt which is logarithmic.
//TC is theta (tight bound) as it always iterate for 32 times
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
int countSetBitsBK(int x) {
	//rightmost set bit(rsb) = x & x" (twos complement of x)
	//x' (ones complement) = ~x
	//x" = x'+1 = ~x+1 = -x (twos complement ox is equivalent to -x)
	int counter = 0;
	while (x != 0) {
		int rsbm = x & -x;
		x -= rsbm;
		counter++;
	}

	return counter;
}

int main()
{
	int i = 70;

	cout << "Number of set Bits Iterate and Count = " << countSetBits(i) << endl;
	cout << "Number of set Bits Brian Kernighan = " << countSetBitsBK(i) << endl;

	return 0;
}
