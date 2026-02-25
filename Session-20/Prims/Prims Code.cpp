class Solution {
  public:
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]); 
        }

        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                if (rank[root_i] < rank[root_j]) {
                    parent[root_i] = root_j;
                } else if (rank[root_i] > rank[root_j]) {
                    parent[root_j] = root_i;
                } else {
                    parent[root_i] = root_j;
                    rank[root_j]++;
                }
                return true;
            }
            return false;
        }
    };

    static bool compareEdges(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }

    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), compareEdges);

        DSU dsu(V);
        int mst_weight = 0;
        int edges_included = 0;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (dsu.unite(u, v)) {
                mst_weight += weight;
                edges_included++;
                
                if (edges_included == V - 1) break;
            }
        }

        return mst_weight;
    }
};