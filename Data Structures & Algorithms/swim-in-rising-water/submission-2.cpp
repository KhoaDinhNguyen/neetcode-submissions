class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void do_union(int x, int y) {
        int parentX = find(x), parentY = find(y);

        if (parentX == parentY) return;

        if (rank[parentX] < rank[parentY]) {
            parent[parentX] = parentY;
        }
        else if (rank[parentY] < rank[parentX]) {
            parent[parentY] = parentX;
        }
        else {
            parent[parentX] = parentY;
            rank[parentY]++;
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> positions;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                positions.push_back({grid[i][j], i, j});
            }
        }

        sort(positions.begin(), positions.end());
        
        DisjointSet djs(N * N);
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


        for (int i = 0; i < positions.size(); ++i) {
            int t = positions[i][0], r = positions[i][1], c = positions[i][2];
            for (const auto& dir: directions) {
                int nextR = r + dir[0], nextC = c + dir[1];

                if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) continue;
                if (grid[nextR][nextC] > t) continue;

                djs.do_union(r * N + c, nextR * N + nextC);
            }

            if (djs.isConnected(0, N * N - 1)) return t;
        }

        return N * N;
    }
};
