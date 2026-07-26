class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    } 

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[px] = py;
            rank[py]++;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        DisjointSet ds(N);
        vector<int> res;

        for (int i = 0; i < N; ++i) {
            if (!ds.unite(edges[i][0] - 1, edges[i][1] - 1)) res = edges[i];
        }

        return res;

    }
};
