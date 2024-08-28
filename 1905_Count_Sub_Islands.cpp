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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n= grid2.size();
        int m= grid2[0].size();
        int res=0;
        int dir[5] = {-1, 0, 1, 0, -1};
        function<int(int, int)> dfs = [&](int i, int j){
            int check = grid1[i][j];
            grid2[i][j]=0;
            for(int k=0; k<4;k++){
                int x= i+dir[k];
                int y= j+dir[k+1];
                if(x>=0 && x<n && y>=0 && y<m && grid2[x][y]){
                    check &= dfs(x, y);
                }
            }
            return check;
        };
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j]){
                    res+= dfs(i, j);
                }
            }
        }
        return res;
    }
};
