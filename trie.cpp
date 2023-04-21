#include <string>
#include "trie.h"

using namespace std;

void Trie::insert(string key, int val) {
    TrieNode *current = root;
    for(char c: key){
        int x = c - 'a';
        if (current -> children[x] == nullptr){
            current -> children[x] = new TrieNode();

        }
        current = current -> children[x];
    }
}

int Trie::search(string key) {
    TrieNode *current = root;
    for (char c : key) {
        int idx = c - 'a';
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
        int idx = c - 'a';
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


