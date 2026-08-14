class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();

        vector<int> ans(N, 0);
        stack<int> s;


        for (int i = N - 1; i >= 0; --i) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }

            if (!s.empty()) {
               ans[i] = s.top() - i;
            }

            s.push(i);
        }

        return ans;

    }
};
