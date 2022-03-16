#include <iostream>
#include <string>
#include < vector>

using namespace std;

int main()
{
	cout << "Enter the sentence: ";
	string input;
	getline(cin, input);

	cout << "Enter the word to seach: ";
	string word;
	getline(cin, word);

	vector<int> indexes;
	int index = input.find(word);
	while (index != -1)
	{
		indexes.push_back(index);
		index = input.find(word, index + 1);
	}

	for (int index : indexes)
		cout << index << endl;

}