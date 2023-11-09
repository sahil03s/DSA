#include <iostream>
#include <vector>

using namespace std;

class TrieNode{
    public :
        char data;
        TrieNode* child[26];
        bool isTerminal;
        int children;
        TrieNode(char ch)
        {
            data = ch;
            for(int i=0; i<26; i++)
                child[i] = NULL;
            isTerminal = false;
            children = 0;
        }
};

class Trie{
    public :
    TrieNode* root;

        Trie()
        {
            root = new TrieNode('\0');
        }

        //T.C. = O(l) where l is length of word
        void insertUtil(TrieNode* root, string word)
        {
            if(word.size() == 0)
            {
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            
            if(root->child[index] == NULL)
            {
                root->child[index] = new TrieNode(word[0]);
                root->children++;
            }

            insertUtil(root->child[index], word.substr(1));
        }

        //T.C. = O(l) where l is length of word
        void insertWord(string word)
        {
            insertUtil(root, word);
        }

        //T.C. = O(l) where l is length of word
        bool searchUtil(TrieNode* root, string word)
        {
            if(!root)
                return false;

            if(word.size() == 0)
                return root->isTerminal;
            
            int index = word[0]-'A';
            if(root->child[index])
                return searchUtil(root->child[index], word.substr(1));
            else
                return false;
        }

        //T.C. = O(l) where l is length of word
        bool searchWord(string word)
        {
            return searchUtil(root, word);
        }

        //T.C. = O(l) where l is length of word
        void removeUtil(TrieNode* &root, string word)
        {
            if(word.size() == 0)
            {
                root->isTerminal = false;
                if(root->children == 0)
                {
                    root = NULL;
                }
                return;
            }

            int index = word[0] - 'A';

            if(root->child[index] == NULL)
                return;
            else if(root->child[index])
                removeUtil(root->child[index], word.substr(1));
            
            if(root->child[index] == NULL)
            {
                root->children--;
                if(root->children == 0)
                    root = NULL;
            }
        }

        //T.C. = O(l) where l is length of word
        void removeWord(string word)
        {
            removeUtil(root, word);
            if(!root)
                root = new TrieNode('\0');

        }


};

int main()
{
    Trie* t = new Trie();
    t->insertWord("SAHIL");
    t->insertWord("ARM");
    t->insertWord("TIME");
    t->insertWord("DO");
    cout << t->searchWord("SAHIL") << endl;
    cout << t->searchWord("SAHIl") << endl;
    cout << t->searchWord("SAHil") << endl;
    cout << t->searchWord("ARM") << endl;
    cout << t->searchWord("AR") << endl;
    cout << t->searchWord("TIME") << endl;
    cout << t->searchWord("TIM") << endl;

    cout << t->searchWord("TIME") << endl;
    t->removeWord("TIME");
    cout << t->searchWord("TIME") << endl;
    t->insertWord("TIME");
    cout << t->searchWord("TIME") << endl;
    t->removeWord("TIME");
    cout << t->searchWord("TIME") << endl;

    // t->insertWord("SAHIL");
    // t->insertWord("STAMP");
    // t->insertWord("STMP");
    // cout << t->searchWord("SAHIL") << endl;

    // cout << t->root->children << endl;

    // t->removeWord("SAHIL");
    // t->removeWord("SAHIL");
    // t->removeWord("SAHIL");
    // t->removeWord("STMP");
    // t->removeWord("STAMP");
    // cout << t->searchWord("SAHIL") << endl;
    // cout << t->root->children << endl;
     

    return 0;
}