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
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long inf = LLONG_MAX / 2;
        const int mod = 1e9 + 7;
        vector<vector<long long>> g(n, vector<long long>(n, inf));
        for (auto& r : roads) {
            int u = r[0], v = r[1], t = r[2];
            g[u][v] = t;
            g[v][u] = t;
        }
        g[0][0] = 0;
        vector<long long> dist(n, inf);
        dist[0] = 0;
        vector<long long> f(n);
        f[0] = 1;
        vector<bool> vis(n);
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                if (j == t) {
                    continue;
                }
                long long ne = dist[t] + g[t][j];
                if (dist[j] > ne) {
                    dist[j] = ne;
                    f[j] = f[t];
                } else if (dist[j] == ne) {
                    f[j] = (f[j] + f[t]) % mod;
                }
            }
        }
        return (int) f[n - 1];
    }
};
