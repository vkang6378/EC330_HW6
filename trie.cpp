#include <string>
#include "trie.h"

using namespace std;

int charToIndex(char c) {
    return c - 'a';
}

char indexToChar(int idx) {
    return 'a' + idx;
}

void Trie::insert(string key, int val) {
    TrieNode *current = root;
    for (char c : key) {
        int idx = charToIndex(c);
        if (current->children[idx] == nullptr) {
            current->children[idx] = new TrieNode();
            tree_size++;
        }
        current = current->children[idx];
    }
    if (current->val == 0) {
        map_size++;
    }
    current->val = val;
}

int Trie::search(string key) {
    TrieNode *current = root;
    for (char c : key) {
        int idx = charToIndex(c);
        if (current->children[idx] == nullptr) {
            return 0;
        }
        current = current->children[idx];
    }
    return current->val;
}

void Trie::remove(string key) {
    TrieNode *current = root;
    for (char c : key) {
        int idx = charToIndex(c);
        if (current->children[idx] == nullptr) {
            return;
        }
        current = current->children[idx];
    }
    if (current->val != 0) {
        current->val = 0;
        map_size--;
    }
}
