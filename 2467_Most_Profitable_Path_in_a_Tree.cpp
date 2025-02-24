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
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> tra(n, n);
        function<bool(int, int, int)> dfs1 = [&](int i, int func, int t){
            if(i == 0){
                tra[i]  = t;
                return true;
            }
            for(int j : g[i]){
                if(j != func && dfs1(j, i, t+1)){
                    tra[j] = min(tra[j], t+1);
                    return true;
                }
            }
            return false;
        };
        dfs1(bob, -1, 0);
        tra[bob] = 0;
        int ans = INT_MIN;
        function<void(int, int, int, int)> dfs2 = [&](int i, int fa, int t, int v){
            if(t == tra[i]){
                v += amount[i] >> 1;
            }
            else if(t < tra[i]){
                v += amount[i];
            }
            if(g[i].size() == 1 && g[i][0] == fa){
                ans = max(ans, v);
                return;
            }
            for(int j : g[i]){
                if(j != fa){
                    dfs2(j, i, t+1, v);
                }
            }
        };
        dfs2(0, -1, 0, 0);
        return ans;
    }
};
