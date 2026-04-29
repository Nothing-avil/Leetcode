// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    long long maximumScore(vector<vector<int>>& g) {
        int n = g.size();
        long long f[n + 1][n + 1][2];
        memset(f, 0, sizeof(f));
        vector<vector<long long>> sum(n, vector<long long>(n + 1));
        for (int i = 0; i < n; i++) {
        sum[i][0] = 0;
        for (int j = 1; j <= n; j++) sum[i][j] = sum[i][j - 1] + g[j - 1][i];
        }
        for (int i = 1; i < n; i++)
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
            long long t = max(f[i - 1][k][0],
                        f[i - 1][k][1] + sum[i - 1][j] - sum[i - 1][k]);
            f[i][j][0] = f[i][j][1] = max(f[i][j][0], t);
            }
            for (int k = j + 1; k <= n; k++) {
            long long t = f[i - 1][k][0];
            f[i][j][0] = max(f[i][j][0], t + sum[i][k] - sum[i][j]);
            f[i][j][1] = max(f[i][j][1], t);
            }
        }
        long long res = 0;
        for (int j = 0; j <= n; j++) res = max(res, f[n - 1][j][0]);
        return res;
    }
};
