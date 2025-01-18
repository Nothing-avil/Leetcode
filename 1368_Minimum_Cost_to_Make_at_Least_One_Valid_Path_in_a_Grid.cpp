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
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        pq.push({0, 0, 0});
        res[0][0] = 0;
        while(pq.size()){
            auto it = pq.top();
            pq.pop();
            int cost = it[2];
            for(int i=0; i<=3; i++){
                int i_ = it[0] + dir[i][0];
                int j_ = it[1] + dir[i][1];
                if(i_ >= 0 && j_ >= 0 && i_ < n && j_ < m){
                    int newcost = cost + (((grid[it[0]][it[1]] -1) != i) ? 1 : 0);
                    if(newcost < res[i_][j_]){
                        res[i_][j_] = newcost;
                        pq.push({i_, j_, newcost});
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};
