class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 1) return false;
        
        unordered_set<int> st;
        k++;

        for (int i = 0; i < k; ++i) {
            if (st.count(nums[i])) return true;
            st.insert(nums[i]);
        }

        for (int i = k; i < nums.size(); ++i) {
            int l = i - k, r = i;

            st.erase(nums[l]);

            if (st.count(nums[r])) return true;

            st.insert(nums[r]);
        }

        return false;
        
    }
};