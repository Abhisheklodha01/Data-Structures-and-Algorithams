#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    // insertion
    void insertUtill(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assumption letters are capital
        int index = word[0] - 'A';
        TrieNode *child;

        // word is present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion

        insertUtill(child, word.substr(1));
    }
    void insert(string word)
    {
        insertUtill(root, word);
    }

    // searching
    bool searchUtill(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return false;
        }

        // recursion
        return searchUtill(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtill(root, word);
    }

    // deletion

    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }

    TrieNode *deleteWordUtill(TrieNode *root, string word, int depth)
    {
        if (root == NULL)
        {
            cout << "nothing to delete" << endl;
            return NULL;
        }

        if (depth == word.length())
        {
            root->isTerminal = false;
            if (isEmpty(root) == true)
            {
                delete (root);
                root = NULL;
            }
            return root;
        }

        int index = word[depth] - 'A';
        root->children[index] = deleteWordUtill(root->children[index], word, depth + 1);

        if (isEmpty(root) && root->isTerminal == false)
        {
            delete (root);
            root = NULL;
        }
        return root;
    }

    void deleteWord(string word, int depth)
    {
        deleteWordUtill(root, word, depth);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("ABCD");
    t->insert("TEKRI");
    t->insert("SARKAR");
    t->insert("GUNA");

    cout << "Present or not: " << t->searchWord("ABCD") << endl;
    cout << "Present or not: " << t->searchWord("ABCDE") << endl;
    cout << "Present or not: " << t->searchWord("ABCE") << endl;
    cout<<"Deletion Begin"<<endl;
    t->deleteWord("ABCD", 0);
    cout << "Present or not: " << t->searchWord("ABCD") << endl;
    return 0;
}