class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        stack<int> left, right;
        vector<int> greater_left(N, -1), greater_right(N, -1);

        for (int i = 0; i < N; ++i) {
            while (!left.empty() && height[i] > height[left.top()]) left.pop();
            if (!left.empty()) greater_left[i] = height[left.top()];
            else left.push(i);
        }

        for (int i = N - 1; i >= 0; --i) {
            while (!right.empty() && height[i] > height[right.top()]) right.pop();
            if (!right.empty()) greater_right[i] = height[right.top()];
            else right.push(i);
        }
        
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            if (greater_left[i] != -1 && greater_right[i] != -1) {
                ans = ans + min(greater_left[i], greater_right[i]) - height[i];
            }
        }

        return ans;
    }
};
