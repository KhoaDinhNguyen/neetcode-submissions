class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        vector<int> score(N, 0);

        for (int i = 0; i < N; ++i) score[i] = gas[i] - cost[i];

        int total = 0;

        for (auto s: score) total += s;

        if (total < 0) return -1;
        
        total = 0;
        int res = 0;

        for (int i = 0; i < N; ++i) {
            total += gas[i] - cost[i];

            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }

        return res;

      
    }
};
