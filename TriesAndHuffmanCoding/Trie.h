#include"TrieNode.h"
#include<iostream>
using namespace std;

class Trie
{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';

        if (root->children[index] == NULL) {
            root->children[index] = new TrieNode(word[0]);
        }

        // Recursive call
        insertWord(root->children[index], word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }

    bool search(TrieNode* root, string word){
        // base case
        if(word.length()==0 && root->isTerminal){
            return true;
        }
        else if(word.length()==0 && !root->isTerminal){
            return false;
        }
        else if(word.length()!=0 && root->children[word[0]-'a']==NULL){
            return false;
        }
    
        return search(root->children[word[0]-'a'], word.substr(1));

    }

    bool search(string word) {
        return search(root,word);
    }

    void removeWord(string word, TrieNode * root){
        // base case
        if(word.length()==0){
            root->isTerminal=false;
            return;
        }

        TrieNode* child = root->children[word[0]-'a'];
        if(child==NULL)
            return;
        // recursion
        removeWord(word.substr(1),child);
        // calculation
        if (child->isTerminal==false)
        {
            for(int i=0; i<26; i++){
                if (child->children[i]!=NULL)
                {
                    return;
                }    
            }
            delete child;
            root->children[word[0]-'a']= NULL;
        }
    }

    void removeWord(string word){
        removeWord(word, root);
    }
};

