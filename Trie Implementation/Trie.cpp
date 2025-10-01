#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node
struct TrieNode {
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(const string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    // Check if any word in the trie starts with the given prefix
    bool startsWith(const string &prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children[ch])
                return false;
            node = node->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("hello");
    trie.insert("world");
    trie.insert("help");
    trie.insert("helium");

    cout << boolalpha; // print true/false instead of 1/0

    cout << "Search 'hello': " << trie.search("hello") << endl;
    cout << "Search 'hel': " << trie.search("hel") << endl;
    cout << "Prefix 'hel': " << trie.startsWith("hel") << endl;
    cout << "Prefix 'wor': " << trie.startsWith("wor") << endl;
    cout << "Search 'world': " << trie.search("world") << endl;

    return 0;
}
