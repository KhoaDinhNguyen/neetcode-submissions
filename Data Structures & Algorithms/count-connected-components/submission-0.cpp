class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        components = n;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[px] = py;
            rank[px]++;
        }
        components--;
    }

    int getComponent() {
        return components;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for (int i = 0; i < edges.size(); ++i) {
            ds.unite(edges[i][0], edges[i][1]);
        }

        return ds.getComponent();
    }
};
