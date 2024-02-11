#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int m = grid.size(), n = grid[0].size();
        int f[m][n][n];
        memset(f, -1, sizeof(f));
        f[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int x = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
                    for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
                        for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
                            if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && f[i - 1][y1][y2] != -1) {
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][y1][y2] + x);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = max(ans, f[m - 1][j1][j2]);
            }
        }
        return ans;
    }
};
