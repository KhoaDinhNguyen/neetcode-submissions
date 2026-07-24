class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;

    TrieNode() {
        children.assign(26, nullptr);
        isWord = false;
    }

     void insert(string word) {
        TrieNode* curr = this;

        for (auto w: word) {
            if (curr->children[w - 'a'] == nullptr) {
                curr->children[w - 'a'] = new TrieNode();
            }
            curr = curr->children[w - 'a'];
        }

        curr->isWord = true;
    }
};

class Solution {
private:
    vector<string> res; 
public:
    void dfs(int r, int c, string word, TrieNode* node, vector<vector<char>>& board) {       
        int N = board.size(), M = board[0].size();

        if (r < 0 || r >= N || 
            c < 0 || c >= M || board[r][c] == '#'
            || node->children[board[r][c] - 'a'] == nullptr) return;
        
        char temp = board[r][c];

        word = word + board[r][c];
        node = node->children[board[r][c] - 'a'];
        board[r][c] = '#';
        
        if (node->isWord) {
            res.push_back(word);
            node->isWord = false;
        }

        dfs(r + 1, c, word, node, board);
        dfs(r - 1, c, word, node, board);
        dfs(r, c + 1, word, node, board);
        dfs(r, c - 1, word, node, board);

        board[r][c] = temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(auto word: words) {
            root->insert(word);
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(i, j, "", root, board);
            }
        }

        return res;
    }
};
