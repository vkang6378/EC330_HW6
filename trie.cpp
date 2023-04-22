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
    
    if (current->val == 0) {
        return; 
    }

    current->val = 0;
    map_size--;

    bool has_children = false;
    for (int i = 0; i < 26; i++) {
        if (current->children[i] != nullptr) {
            has_children = true;
            break;
        }
    }

    if (!has_children) {
        TrieNode *parent = root;
        for (char c : key) {
            int x = c - 'a';
            if (parent->children[x] == current) {
                delete parent->children[x];
                parent->children[x] = nullptr;
                tree_size--;
                break;
            }
            parent = parent->children[x];
        }
    }
}


