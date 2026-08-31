class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int charFreq[26] = {0};

        for (int i = 0; i < tasks.size(); ++i) {
            charFreq[tasks[i] - 'A']++; 
        }    


        priority_queue<pair<int, char>> pq;
        queue<pair<int, char>> wait;

        for (int i = 0; i < 26; ++i) {
            if (charFreq[i] > 0) pq.push({charFreq[i], i + 'A'});
        }

        int time = 1;

        while (!pq.empty() || !wait.empty()) {
            while (!wait.empty() && wait.front().first <= time) {
                char c = wait.front().second;
                wait.pop();

                int freq = charFreq[c - 'A'];

                pq.push({freq, c});
            }

            if (!pq.empty()) {
                char c = pq.top().second;
                charFreq[c - 'A']--;

                pq.pop();

                if (charFreq[c - 'A'] > 0) {
                    wait.push({time + n + 1, c});
                }
            }

            time++;
        }

        return time - 1;
    }
};
