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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> g(n);
        vector<int> degree(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
            ++degree[a];
            ++degree[b];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.clear();
            for (int i = q.size(); i > 0; --i) {
                int a = q.front();
                q.pop();
                ans.push_back(a);
                for (int b : g[a]) {
                    if (--degree[b] == 1) {
                        q.push(b);
                    }
                }
            }
        }
        return ans;
    }
};
