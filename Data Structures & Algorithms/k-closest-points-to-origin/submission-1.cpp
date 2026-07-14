class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](const pair<double, vector<int>> &a, const pair<double, vector<int>> &b) {
            return a.first < b.first;   
        };

        priority_queue<pair<double, vector<int>>, 
                    vector<pair<double, vector<int>>>,
                    decltype(compare)> q(compare);

        for (int i = 0; i < points.size(); ++i) {
            double dis = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));

            if (q.size() >= k) {
                double maxDis = q.top().first;
                if (maxDis > dis) {
                    q.pop();
                    q.push(make_pair(dis, points[i]));
                }
            }
            else {
                q.push(make_pair(dis, points[i]));
            }
        }

        vector<vector<int>> res;

        while (q.size() > 0) {
            res.push_back(q.top().second);
            q.pop();
        }
        
        return res;
    }
};
