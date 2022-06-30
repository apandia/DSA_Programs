#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> splitString(string str)
{
	vector<string> result;

	size_t startPos = 0;
	size_t endPos = 0;

	while ((endPos = str.find(" ", startPos)) != string::npos)
	{
		result.push_back(str.substr(startPos, endPos - startPos));

		startPos = endPos + 1;
	}

	result.push_back(str.substr(startPos));

	return result;
}

//Driver function
int main()
{
	string str = "Hello World!";

	vector<string> result = splitString(str);

	for (auto str : result) {
		cout << str << " " << endl;
	}

	return 0;
}
