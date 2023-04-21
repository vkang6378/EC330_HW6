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
        }
        current = current -> children[x];
    }
    if (current->val == 0) {
        map_size++;  

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
    int x = c - 'a';
    for (char c : key) {
        if (current->children[x] == nullptr) {
            return;
        }
        current = current->children[x];
    }
    if (current->val != 0) {
        current->val = 0;
        map_size--;
    }
    for (key : current.empty() != true)
        delete node;
    }
}

