class DisjointSet {
public:
    vector<int> rank;
    vector<int> parent;

    DisjointSet(int n) {
        rank = vector<int>(n, 0);
        parent = vector<int>(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void do_union(int x, int y){
        int parentX = find(x);
        int parentY = find(y);

        if (rank[parentX] < rank[parentY]) {
            parent[parentX] = parentY;
        }
        else if (rank[parentX] > rank[parentY]) {
            parent[parentY] = parentX;
        }
        else {
            parent[parentX] = parentY;
            rank[parentY]++;
        }
    }

    bool isInComponent(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int distance(vector<int>& i, vector<int>& j) {
        return abs(i[0] - j[0]) + abs(i[1] - j[1]);
    }

    // Krusal
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        DisjointSet djs(N);

        vector<vector<int>> edges;
    
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                edges.push_back({distance(points[i], points[j]), i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int M = edges.size();
        int ans = 0;

        for (int i = 0; i < M; ++i) {
            int cost = edges[i][0], x = edges[i][1], y = edges[i][2];

            if (!djs.isInComponent(x, y)) {
                ans += cost;
                djs.do_union(x, y);
            }
        }

        return ans;
        
    }
};
