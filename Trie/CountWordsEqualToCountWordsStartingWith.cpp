#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
class TrieNode
{
	TrieNode* links[ALPHABET_SIZE];
	int countNumberOfWords; //store the count for words that trie contains
	int countPrefix;//store the number of words possible for a given prefix

public:
	TrieNode() {
		for (int i = 0; i < ALPHABET_SIZE; i++)
			links[i] = NULL;

		countNumberOfWords = 0;
		countPrefix = 0;
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

	void increaseNumberOfWords() {
		countNumberOfWords++;
	}

	void increasePrefix() {
		countPrefix++;
	}

	void decreaseNumberOfWords() {
		countNumberOfWords--;
	}

	void decreasePrefix() {
		countPrefix--;
	}

	int getNumberOfWords() {
		return countNumberOfWords;
	}

	int getPrefix() {
		return countPrefix;
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
			node->increasePrefix();
		}

		node->increaseNumberOfWords();
	}

	int countWordsEqualTo(string word) {
		TrieNode* node = root;

		for (int i = 0; i < word.length(); i++) {
			if (node->containsKey(word[i])) {
				node = node->get(word[i]);
			}
			else {
				return 0;
			}
		}

		return node->getNumberOfWords();
	}

	int countWordsStartsWith(string word) {
		TrieNode* node = root;

		for (int i = 0; i < word.length(); i++) {
			if (node->containsKey(word[i])) {
				node = node->get(word[i]);
			}
			else {
				return 0;
			}
		}

		return node->getPrefix();
	}

	void remove(string word) {
		TrieNode* node = root;

		for (int i = 0; i < word.length(); i++) {
			if (node->containsKey(word[i])) {
				node = node->get(word[i]);
				node->decreasePrefix();
			}
			else {
				return;
			}
		}

		return node->decreaseNumberOfWords();
	}
};

//Driver function
int main()
{
	Trie* t = new Trie();

	t->insert("apple");
	t->insert("apple");
	t->insert("application");
	
	t->insert("orange");
	t->remove("orange");

	cout << "CountWordsEqualTo apple = " << t->countWordsEqualTo("apple") << endl;
	
	cout << "CountWordsStartingWith app = " << t->countWordsStartsWith("app") << endl;

	cout << "CountWordsEqualTo orange = " << t->countWordsEqualTo("orange") << endl;

	return 0;
}
