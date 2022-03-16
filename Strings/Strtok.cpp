
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Enter string for strtok: ";
	char input[1000];
	cin.getline(input, 1000);

	char* ch = strtok(input, " ");

	while (ch)
	{
		cout << ch << endl;
		ch = strtok(NULL, " ");
	}

	cout << "Enter string for strtok_s: ";
	char input1[1000];
	cin.getline(input1, 1000);
	char *next_token;
	char* ch1 = strtok_s(input1, " ", &next_token);
	while (ch1)
	{
		cout << ch1 << endl;
		ch1 = strtok_s(NULL, " ", &next_token);
	}
}