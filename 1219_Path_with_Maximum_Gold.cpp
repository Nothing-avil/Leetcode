#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        function<int(int,int)> dfs=[&](int s, int e){
            if (s < 0 || s >= n || e < 0 || e >= m || !grid[s][e]) {
                return 0;
            }
            int v = grid[s][e];
            grid[s][e] = 0;
            int ans = v + max({dfs(s - 1, e), dfs(s + 1, e), dfs(s, e - 1), dfs(s, e + 1)});
            grid[s][e] = v;
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
