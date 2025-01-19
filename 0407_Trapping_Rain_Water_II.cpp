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
    int trapRainWater(vector<vector<int>>& heightMap) {
        using pp = pair<int,pair<int, int>>;
        priority_queue<pp, vector<pp>, greater<>> pq;
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || j == 0 || i==n-1 || j== m-1){
                    pq.push({heightMap[i][j], {i,j}});
                    vis[i][j] = true;
                }
            }
        }
        int water = 0;
        vector<vector<int>> dir = {{0 ,-1}, { 0, 1}, {-1, 0}, {1, 0}};
        while(!pq.empty()){
            pp it = pq.top();
            pq.pop();
            int h = it.first;
            int i = it.second.first;
            int j = it.second.second;
            for(auto d : dir){
                int i_ = i + d[0];
                int j_ = j + d[1];
                if(i_>=0 && j_>=0 && i_<n && j_<m && !vis[i_][j_]){
                    water += max(h-heightMap[i_][j_], 0);
                    vis[i_][j_] = true;
                    pq.push({max(h, heightMap[i_][j_]), {i_, j_}});
                }
            }
        }
        return water;
    }
};
