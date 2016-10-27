#include"Inc.h"
class TrieNode {
public:
	TrieNode *next[26];
	bool isWord;
	// Initialize your data structure here.
	TrieNode():isWord(false) {
		memset(next, NULL, sizeof(next));
	}
};

class Trie {
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode *p = root;
		for (auto &a : word) {
			if (!p->next[a - 'a'])
				p->next[a - 'a'] = new TrieNode();
			p = p->next[a - 'a'];
		}
		p->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *p = find(word);
		return p&&p->isWord;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		return find(prefix) != NULL;
	}

private:
	TrieNode* find(string key) {
		TrieNode *p = root;
		for (auto &a : key) {
			if (p) p = p->next[a - 'a'];
			else break;
		}
		return p;
	}
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");