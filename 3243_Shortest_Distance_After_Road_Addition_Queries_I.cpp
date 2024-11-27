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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        for(int i= 0; i<n-1; i++){
            mp[i].push_back(i+1);
        }
        auto bfs = [&](int i) -> int{
            queue<int> qu;
            qu.push(i);
            vector<bool> vis(n);
            vis[i] = true;
            for(int l = 0; ; ++l){
                int a = qu.size();
                while(a--){
                    int u = qu.front();
                    qu.pop();
                    if(u == n-1){
                        return l;
                    }
                    for(int v : mp[u]){
                        if(!vis[v]){
                            vis[v] = true;
                            qu.push(v);
                        }
                    }
                }
            }
        };
        vector<int> res;
        for(auto i : queries){
            mp[i[0]].push_back(i[1]);
            res.push_back(bfs(0));
        }
        return res;
    }
};
