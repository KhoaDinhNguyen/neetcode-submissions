class CountSquares {
public:
    unordered_map<long, int> ptsCount;
    vector<vector<int>> pts;

    long getKey(int x, int y) {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ptsCount[getKey(point[0], point[1])]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        // two points act like square main diagonal
        int ans = 0;

        for (int i = 0; i < pts.size(); ++i) {
            int diffX = abs(pts[i][0] - point[0]);
            int diffY = abs(pts[i][1] - point[1]);

            if (diffX == 0 || diffY == 0) continue;

            // find top right points
            int numTopRight = ptsCount[getKey(point[0], pts[i][1])];
            int numBottomLeft = ptsCount[getKey(pts[i][0], point[1])];

            ans += numTopRight * numBottomLeft;
        }

        return ans;
    }
};
