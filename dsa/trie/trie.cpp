/* TOPIC: Tries */

// REFERENCE: https://youtu.be/Y6dOuGjwsxU

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:

    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for (int i=0; i<26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }

};

class Trie {
private:

    TrieNode* root;

    // recursive helper function to add a word in trie
    void insertUtil(TrieNode* root, string word) {

        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // finding index and making child trie node of character
        int index = word[0] - 'A';
        TrieNode* child;

        // character present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }

        // character absent
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));

    }

    // recursive helper function to search a word in trie
    bool searchUtil(TrieNode* root, string word) {

        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        // finding index and child trie node of character
        int index = word[0] - 'A';
        TrieNode* child;

        // character present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }

        // character absent
        else {
            return false;
        }

        // recursive call
        return searchUtil(child, word.substr(1));

    }

    // recursive helper function to delete a word in trie
    void removeUtil(TrieNode* root, string word) {

        // base case
        if (word.length() == 0) {
            root->isTerminal = false;
            return;
        }

        // finding index and child trie node of character
        int index = word[0] - 'A';
        TrieNode* child;


        // character present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }

        // character absent
        else {
            return;
        }

        // recursive call
        removeUtil(child, word.substr(1));

    }

public:

    // constructor
    Trie() {
        root = new TrieNode('\0');
    }

    // add a word in trie
    void insert(string word) {
        insertUtil(root, word);
    }

    // search a word in trie
    bool search(string word) {
        return searchUtil(root, word);
    }

    // delete a word in trie
    void remove(string word) {
        removeUtil(root, word);
    }

};

int main() {

    Trie *t = new Trie();

    // insert in trie
    t->insert("SAHIL");
    t->insert("SACHIN");
    t->insert("SONAM");
    t->insert("SONU");

    // search in trie
    cout << t->search("SACHIN") << endl;

    // delete in trie
    t->remove("SACHIN");

    // search in trie
    cout << t->search("SACHIN") << endl;

    return 0;
}