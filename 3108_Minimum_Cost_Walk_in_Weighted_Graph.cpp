// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    vector<int> minimumCost(int N, vector<vector<int>>& edges, vector<vector<int>>& querys) {
        vector<vector<int>> adj(N);
        vector<int> c(N, (1 << 30) - 1);
        for (vector<int> edge : edges) {
            int u = edge[0], v = edge[1], k = edge[2];
            adj[u].push_back(v);
            adj[v].push_back(u);
            c[u] = c[u] & k;
            c[v] = c[v] & k;
        }
        queue<int> q;
        vector<int> group(N, -1);
        for (int i = 0; i < N; i++) {
            if (group[i] == -1) {
                group[i] = i;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    c[i] = c[i] & c[u];
                    for (int v : adj[u]) {
                        if (group[v] == -1) {
                            group[v] = i;
                            q.push(v);
                        }
                    }
                }
            }
        }
        vector<int> res;
        for (vector<int> query : querys) {
            int s = query[0], t = query[1];
            if (s == t) {
                res.push_back(0);
            } else {
                if (group[s] == group[t]) {
                    res.push_back(c[group[s]]);
                } else {
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};
