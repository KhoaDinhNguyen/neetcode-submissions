class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> q;

        for (int i = 0; i < stones.size(); ++i) q.push(stones[i]);

        while (q.size() > 1) {
            int stone1 = q.top();
            q.pop();
            int stone2 = q.top();
            q.pop();

            if (stone2 != stone1) {
                int stoneLeft = abs(stone1 - stone2);
                q.push(stoneLeft);
            }
        }

        return q.size() == 0? 0: q.top();
    }
};
