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
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        const int mod = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        int f[m][n][K];
        memset(f, 0, sizeof(f));
        f[0][0][grid[0][0] % K] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < K; ++k) {
                    int k0 = ((k - grid[i][j] % K) + K) % K;
                    if (i > 0) {
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j][k0]) % mod;
                    }
                    if (j > 0) {
                        f[i][j][k] = (f[i][j][k] + f[i][j - 1][k0]) % mod;
                    }
                }
            }
        }
        return f[m - 1][n - 1][0];
    }
};
