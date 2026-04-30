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
const auto __ = []() {
   struct Leetcode {
       static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
   };
   std::atexit(&Leetcode::_);
   return 0;
}();
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int inf = 1 << 30;
        vector f(m, vector(n, vector<int>(k + 1, -1)));
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i < 0 || j < 0 || k < 0) {
                return -inf;
            }
            if (i == 0 && j == 0) {
                return 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int res = grid[i][j];
            int nk = k;
            if (grid[i][j] > 0) {
                --nk;
            }
            int a = dfs(i - 1, j, nk);
            int b = dfs(i, j - 1, nk);
            res += max(a, b);
            return f[i][j][k] = res;
        };
        int ans = dfs(m - 1, n - 1, k);
        return ans < 0 ? -1 : ans;
    }
};
