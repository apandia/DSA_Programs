#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
class TrieNode
{
	TrieNode* links[ALPHABET_SIZE];
	bool endOfWord;

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

	bool checkIfPrefixExist(string word) {
		TrieNode* node = root;
		bool result = true;

		for (int i = 0; i < word.length(); i++) {
			if (node->containsKey(word[i])) {
				node = node->get(word[i]);
				result = result & node->isEnd();
			}
			else {
				return false;
			}		
		}

		return result;
	}	
};

//Driver function
int main()
{
	vector<string> input{ "a", "apple", "appl", "ap", "app", "apps" };

	Trie* t = new Trie();

	for (auto word : input) {
		t->insert(word);
	}

	string longest = "";

	for (auto word : input) {
		if (t->checkIfPrefixExist(word))
		{
			if (word.length() > longest.length()) {
				longest = word;
			}
			else if (word.length() == longest.length() && word < longest) {
				longest = word;
			}			
		}
	}

	cout << "Longest word is " << longest;

	return 0;
}
