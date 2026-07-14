class Solution {
public:
    double solution(vector<int>& nums1, vector<int>& nums2) {
        // N < M
        int N = nums1.size(), M = nums2.size();

        int l = 0, r = N - 1, total = M + N, half = total / 2;

        while (true) {
            int i = l + (r - l) / 2;
            int j = half - i;
            
            int Aleft = i > 0? nums1[i - 1]: INT_MIN;
            int Aright = i < N ? nums1[i] : INT_MAX;
            int Bleft = j > 0? nums2[j - 1]: INT_MIN;
            int Bright = j < M? nums2[j] : INT_MAX;
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1) return min(Aright, Bright);
                
                return (min(Aright, Bright) + max(Aleft, Bleft)) / 2.0;
            }
            else if (Aleft > Bright) r = i - 1;
            else l = i + 1;
        }

        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return nums1.size() < nums2.size()? solution(nums1, nums2): solution(nums2, nums1);
    }
};
