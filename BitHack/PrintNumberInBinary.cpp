#include <iostream>
#include <string>

using namespace std;

string printBinary(int number)
{
	string temp;

	while (number) {
		if (number % 2 == 0)
			temp += "0";
		else
			temp += "1";

		number = number / 2;
	}

	//reverse the string now
	reverse(temp.begin(), temp.end());

	return temp;
}

int main()
{
	//int number = 235; //11101011
	int number = 8;
	cout << printBinary(number) << endl;

	return 0;
}
