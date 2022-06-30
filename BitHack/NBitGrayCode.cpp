#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> printNBitGrayCode(int n)
{
	if (n <= 0)
		return{ "0" };

	if (n == 1)
	{
		return {"0", "1"};
	}

	vector<string> output = printNBitGrayCode(n - 1);

	vector<string> temp;
	string str;

	//read the element in normal order and prepend 0 
	for (int i = 0; i < output.size(); i++)
	{
		str = "0" + output[i];
		temp.push_back(str);
	}

	//read the element in reverse order and prepend 1 
	for (int i = output.size()-1; i >= 0 ; i--)
	{
		str = "1" + output[i];
		temp.push_back(str);
	}

	return temp;
}

int main()
{
	int n;
	cout << "Input n:";
	cin >> n;

	vector<string> result = printNBitGrayCode(n);

	cout << "[";
	for (string x : result)
		cout << "\"" << x << "\", ";

	cout << "]"<<endl;

	return 0;
}

//Time Complexity : O(2^N)
//Auxiliary Space : O(2^N)