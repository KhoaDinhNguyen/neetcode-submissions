class Solution {
public:
    string merge(string& word1, string& word2, int i, int j) {
        if (i == word1.size()) return word2.substr(j);
        else if (j == word2.size()) return word1.substr(i);

        string curr = "";
        curr += word1[i];
        curr += word2[j];
        
        return curr + merge(word1, word2, i + 1, j + 1); 
    }
    string mergeAlternately(string word1, string word2) {
        return merge(word1, word2, 0, 0);
    }
};