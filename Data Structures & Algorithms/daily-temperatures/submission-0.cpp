class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /**
        Brute force:
            start from right and count O(N^2)


        
        **/

        int N = temperatures.size();

        vector<int> ans(N, 0);
        stack<int> st;

        for (int i = N - 1; i >= 0; --i) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) st.pop();

            if (st.empty()) ans[i] = 0;
            else ans[i] = st.top() - i;

            st.push(i);
        }

        return ans;
    }
};
