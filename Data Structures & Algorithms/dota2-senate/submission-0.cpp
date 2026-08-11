class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R, D;
        int N = senate.size();

        for (int i = 0; i < N; ++i) {
            if (senate[i] == 'R') {
                R.push(i);
            }
            else {
                D.push(i);
            }
        }

        while (!R.empty() && !D.empty()) {
            int RTurn = R.front();
            int DTurn = D.front();

            D.pop();
            R.pop();

            if (RTurn < DTurn) {  
                R.push(RTurn + N);
            }
            else {
                D.push(DTurn + N);
            }
        }

        return R.empty()? "Dire" : "Radiant";
    }
};