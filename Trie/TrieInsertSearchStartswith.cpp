#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
class TrieNode
{
	TrieNode* links[ALPHABET_SIZE];
	bool endOfWord; //true if end of word, false otherwise

public:
	TrieNode() {
		for (int i = 0; i < ALPHABET_SIZE; i++)
			links[i] = NULL;

		endOfWord = false;
	}

	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	void put(char ch, TrieNode* node) {
		links[ch - 'a'] = node;
	}

	TrieNode* get(char ch) {
		return links[ch - 'a'];
	}

	void setEnd() {
		endOfWord = true;
	}

	bool isEnd() {
		return endOfWord;
	}
};

class Trie {
	TrieNode* root;

public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode* node = root;

		for (int i = 0; i < word.length(); i++) {
			if (!node->containsKey(word[i])) {
				node->put(word[i], new TrieNode());
			}

			node = node->get(word[i]);
		}

		node->setEnd();
	}

	bool search(string word) {
		TrieNode* node = root;

		for (int i = 0; i < word.length(); i++) {
			if (!node->containsKey(word[i])) {
				return false;
			}

			//Move the reference node
			node = node->get(word[i]);
		}

		return node->isEnd();
	}

	bool startsWith(string word) {
		TrieNode* node = root;
		for (int i = 0; i < word.length(); i++) {
			if (!node->containsKey(word[i])) {
				return false;
			}

			node = node->get(word[i]);
		}

		return true;
	}
};

//Driver function
int main()
{
	vector<string> input{ "apple", "ball", "cat", "dog" };

	Trie* t = new Trie();

	for (auto word : input) {
		t->insert(word);
	}

	if (t->search("apple")) {
		cout << "apple is found in trie" << endl;
	}
	else
	{
		cout << "apple is not found in trie" << endl;
	}

	if (t->startsWith("app"))
	{
		cout << "Word that startsWith app is found in trie" << endl;
	}
	else
	{
		cout << "Word that startsWith app is not found in trie" << endl;
	}

	if (t->startsWith("ba"))
	{
		cout << "Word that startsWith ba is found in trie" << endl;
	}
	else
	{
		cout << "Word that startsWith ba is not found in trie" << endl;
	}

	if (t->startsWith("z"))
	{
		cout << "Word that startsWith z is found in trie" << endl;
	}
	else
	{
		cout << "Word that startsWith z is not found in trie" << endl;
	}

	return 0;
}
