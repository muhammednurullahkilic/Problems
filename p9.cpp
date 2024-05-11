#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEndOfWord = false;
    }
};


void insertWord(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'A'; 
        if (!node->children[index])
            node->children[index] = new TrieNode();
        node = node->children[index];
    }
    node->isEndOfWord = true;
}


void findWordsUtil(vector<vector<char>>& board, int i, int j, TrieNode* root, string& path, unordered_set<string>& result, vector<vector<bool>>& visited) {
    int rows = board.size();
    int cols = board[0].size();

    
    if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j])
        return;

 
    int index = board[i][j] - 'A'; 
    TrieNode* child = root->children[index];

    
    if (!child)
        return;

   
    path.push_back(board[i][j]);
    visited[i][j] = true;

   
    if (child->isEndOfWord)
        result.insert(path);

    
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0)
                continue;
            findWordsUtil(board, i + x, j + y, child, path, result, visited);
        }
    }

  
    path.pop_back();
    visited[i][j] = false;
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    TrieNode* root = new TrieNode();
    unordered_set<string> result;

    
    for (string word : dictionary)
        insertWord(root, word);

    int rows = board.size();
    int cols = board[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            string path = "";
            findWordsUtil(board, i, j, root, path, result, visited);
        }
    }

    vector<string> words(result.begin(), result.end());
    return words;
}

int main() {
    vector<vector<char>> board = { {'G','I','Z'}, {'U','E','K'}, {'Q','S','E'} };
    vector<string> dictionary = { "GEEKS","FOR","QUIZ","GO" };

    vector<string> result = wordBoggle(board, dictionary);

    for (string word : result)
        cout << word << " ";

    return 0;
}
