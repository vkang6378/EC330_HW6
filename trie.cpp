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
            return; // The key is not in the trie, so we cannot remove it
        }
        current = current->children[x];
    }
    
    if (current->val == 0) {
        return; // The key is not in the trie, so we cannot remove it
    }

    // Set the value to 0, indicating that the key has been removed
    current->val = 0;
    map_size--;

    // Check if the current node has any children
    bool has_children = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (current->children[i] != nullptr) {
            has_children = true;
            break;
        }
    }

    // If the current node has no children, remove it and update the tree_size
    if (!has_children) {
        TrieNode *parent = root;
        for (char c : key) {
            int x = c - 'a';
            TrieNode *next_node = parent->children[x];
            if (next_node == current) {
                parent->children[x] = nullptr;
                delete current;
                tree_size--;
                break;
            }
            parent = next_node;
        }
    }
}




