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
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        const int n = colors.length();
        int ans = 0;
        int processed = 0;
        vector<vector<int>> graph(n);
        vector<int> inDegree(n);
        queue<int> q;
        vector<vector<int>> count(n, vector<int>(26));
        for (const vector<int>& edge : edges) {
        const int u = edge[0];
        const int v = edge[1];
        graph[u].push_back(v);
        ++inDegree[v];
        }
        for (int i = 0; i < n; ++i)
        if (inDegree[i] == 0)
            q.push(i);
        while (!q.empty()) {
            const int out = q.front();
            q.pop();
            ++processed;
            ans = max(ans, ++count[out][colors[out] - 'a']);
            for (const int in : graph[out]) {
                for (int i = 0; i < 26; ++i)
                    count[in][i] = max(count[in][i], count[out][i]);
                if (--inDegree[in] == 0)
                q.push(in);
            }
        }
        return processed == n ? ans : -1;
    }
};
