class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();

        vector<int> left(N, 0), right(N, 0);

        left[0] = nums[0];
        right[N - 1] = nums[N - 1];

        for (int i = 1; i < N; ++i) {
            if (i % k == 0) {
                left[i] = nums[i];
            }
            else {
                left[i] = max(left[i - 1], nums[i]);
            }

            if ((N - 1 - i) % k == 0) {
                right[N - 1 - i] = nums[N - 1 - i];
            }
            else {
                right[N - 1 - i] = max(right[N - i], nums[N - 1 - i]);
            }
        }
        
        for (int i = 0; i < N; ++i) {
            cout<< left[i] << " ";
        }

        cout << endl;

        for (int i = 0; i < N; ++i) {
            cout<< right[i] << " ";
        }

        vector<int> ans;

        for (int i = 0; i < N - k + 1; ++i) {
            ans.push_back(max(right[i], left[i + k - 1]));
        }

        return ans;

    }
};
