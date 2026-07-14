class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](const pair<double, vector<int>> &a, const pair<double, vector<int>> &b) {
            return a.first > b.first;   
        };

        priority_queue<pair<double, vector<int>>, 
                    vector<pair<double, vector<int>>>,
                    decltype(compare)> q(compare);

        for (int i = 0; i < points.size(); ++i) {
            double dis = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2)); 
            q.push(make_pair(dis, points[i]));
        }

        vector<vector<int>> res;

        while (k > 0) {
            pair<double, vector<int>> curr = q.top();
            q.pop();

            res.push_back(curr.second);
            k--;
        }
        
        return res;
    }
};
