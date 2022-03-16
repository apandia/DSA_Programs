#include <iostream>
#include <string>
#include < vector>
#include <sstream>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	stringstream ss(input);

	string token;
	vector<string> tokens;
	while (getline(ss, token, ' '))
	{
		tokens.push_back(token);
	}

	for (string token : tokens)
	{
		cout << token << ",";
	}
	cout << endl;
}