class Solution {
public:
    int cal(int n) {
        int res = 0;

        while (n > 0) {
            res = res + (n % 10) * (n % 10);
            n = n / 10;
        }

        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> st;

        while (true){
            n = cal(n);

            if (n == 1) break;
            if (st.find(n) != st.end()) return false;

            st.insert(n);
        }

        return true;
    }
};
