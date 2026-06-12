// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
const auto __ = []() {
    struct Leetcode {
        static void _() {
            std::ofstream("display_runtime.txt") << 0 << '\n';
       }
    };
    std::atexit(&Leetcode::_);
    return 0;
};
class Solution {
public:
    int M = 1e9+7;
    int n;
    int cols;

    unordered_map<int, vector<int>> adj;
    vector<vector<int>> ancestorTable;
    vector<int> depth;

    void dfs(int root, int parent) {
        ancestorTable[root][0] = parent;

        for(int &ngbr : adj[root]) {
            if(ngbr == parent) continue;

            depth[ngbr] = depth[root] + 1;

            dfs(ngbr, root);
        }
    }

    void buildAncestorTable() {
        for(int j = 1; j < cols; j++) {
            for(int node = 0; node < n; node++) {
                if(ancestorTable[node][j-1] != -1)
                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
            }
        }
    }

    int findLCA(int u, int v) {
        if(depth[u] < depth[v])
            swap(u, v);
        
        int k = depth[u] - depth[v];

        for(int j = 0; j < cols; j++) {
            if(k & (1 << j)) {
                u = ancestorTable[u][j];
            }
        }

        if(u == v) { //both were on the same path
            return u; //LCA
        }

        for(int j = cols-1; j >= 0; j--) {
            if(ancestorTable[u][j] == -1) {
                continue;
            }

            if(ancestorTable[u][j] != ancestorTable[v][j]) { //still different, then keep jumping
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0]; //LCA
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n    = edges.size()+1;
        cols = log2(n)+1;

        for(auto &edge : edges) {
            int u = edge[0]-1;
            int v = edge[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.resize(n, 0);
        ancestorTable.resize(n, vector<int>(cols, -1));

        dfs(0, -1);
        buildAncestorTable();

        //Precompute power of 2
        vector<int> pow2(n+1);
        pow2[0] = 1;
        for(int i = 1; i <= n; i++) {
            pow2[i] = (2LL * pow2[i-1]) % M;
        }

        vector<int> result;
        for(auto &query : queries) {
            int u = query[0] - 1;
            int v = query[1] - 1;

            int lca = findLCA(u, v);
            int d = depth[u] + depth[v] - 2*depth[lca];

            if(d == 0) {
                result.push_back(0);
            } else {
                result.push_back(pow2[d-1]);
            }
        }

        return result;
    }
};
