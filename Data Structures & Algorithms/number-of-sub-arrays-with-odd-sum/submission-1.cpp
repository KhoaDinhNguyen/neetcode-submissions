class Solution {
public:
    /**
    The idea is at every number
    - if the number is odd -> the res += number of even length
    - if the number is even -> the res += number of odd length
    **/
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0, evenCnt = 0, oddCnt = 0, acc = 0;


        for (int i = 0; i < arr.size(); ++i) {
            acc += arr[i];

            if (acc % 2 == 0) {
                ans += (oddCnt);
                evenCnt++;
            }
            else {
                ans += (1 + evenCnt);
                oddCnt++;
            }
        }

        return ans;
    }
};