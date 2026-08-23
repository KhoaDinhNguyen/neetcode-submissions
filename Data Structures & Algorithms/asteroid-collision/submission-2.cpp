class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        int N = asteroids.size();

        for (int i = 0; i < N; ++i) {
            int stone = asteroids[i];

            while (!st.empty() && stone < 0 && st.back() > 0) {
                int diff = stone + st.back();

                if (diff <= 0) st.pop_back();
                if (diff >= 0) stone = 0;
            }

            if (stone != 0) {
                st.push_back(stone);
            } 
        }

        return st;
    }
};