class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size(), totalGas = 0, totalCost = 0;
        for (int g: gas) totalGas += g;
        for (int c: cost) totalCost += c;

        if (totalGas < totalCost) return -1;
       
        int total = 0, res = 0;

        for (int i = 0; i < N; ++i) {
            total += gas[i] - cost[i];

            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }

        return res;
    }
};
