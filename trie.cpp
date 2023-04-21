#include <string>
#include "trie.h"

using namespace std;

void Trie::insert(string key, int val) {
    TrieNode *current = root;
    for(char c: key){
        int x = c - 'a';
        if (current -> children[x] == nullptr){
            current -> children[x] = new TrieNode();
            tree_size++;    
            map_size++;
        }
        current = current -> children[x];
    }
    current->val = val;
}

int Trie::search(string key) {
    TrieNode *current = root;
    for (char c : key) {
        int x = c - 'a';
        if (current -> children[x] == nullptr) {
            return 0;
        }
        current = current->children[x];
    }
    return current->val;
}

void Trie::remove(string key) {
    TrieNode *current = root;
    for (char c : key) {
        int x = c - 'a';
        if (current->children[x] == nullptr) {
            return;
        }
        current = current->children[x];
    }
    if (current->val != 0) {
        current->val = 0;
        map_size--;
    }
}


