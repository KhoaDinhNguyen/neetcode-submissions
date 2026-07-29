class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> note(26, 0);
        vector<int> maga(26, 0);

        for (int i = 0; i < ransomNote.size(); ++i) {
            note[ransomNote[i] - 'a']++;
        }

        for (int i = 0; i < magazine.size(); ++i) {
            maga[magazine[i] - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (maga[i] < note[i]) return false;
        }

        return true;
    }
};