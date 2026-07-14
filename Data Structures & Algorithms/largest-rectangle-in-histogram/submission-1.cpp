class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();

        /**
        left: at i, the first index j  such that height[i] > height[j]. -1 if no such exists
        right: at i, the first index j such that height[i] > height[j]. N if no such exists
        **/
        vector<int> left(N, -1), right(N, N);

        stack<int> leftSt, rightSt;

        for (int i = 0; i < N; ++i) {
            while (!leftSt.empty() && heights[i] <= heights[leftSt.top()]) leftSt.pop();
            while (!rightSt.empty() && heights[N - 1 - i] <= heights[rightSt.top()]) rightSt.pop();

            if (!leftSt.empty()) left[i] = leftSt.top();
            if (!rightSt.empty()) right[N - 1 - i] = rightSt.top();

            leftSt.push(i);
            rightSt.push(N - 1 - i);
        }

        int ans = 0;

        for (int i = 0; i < N; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }

        return ans;
    }
};
