class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> neg;
        vector<int> pos;

        int N = asteroids.size();

        for (int i = 0; i < N; ++i) {
            int stone = asteroids[i];

            if (stone < 0) {
                bool destroyed = false;

                while (!pos.empty() && !destroyed) {
                    int posStone = pos.back();

                    if (abs(stone) >= posStone) pos.pop_back();
                    if (abs(stone) <= posStone) destroyed = true;                    
                }

                if (!destroyed) {
                    neg.push_back(stone);
                }
            }
            else {
                pos.push_back(stone);
            }
        }

        vector<int> ans(neg.begin(), neg.end());

        ans.insert(ans.end(), pos.begin(), pos.end());

        return ans;
        
    }
};