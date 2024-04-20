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
    int row, col;
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& grid, int i, int j, int& r, int& c){
        
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] != 1)
            return;
        
        grid[i][j]=0;


        r= max(r, i);
        c= max(c, j);

        dfs(grid, i+1,j, r, c);
        dfs(grid, i-1,j, r, c);
        dfs(grid, i,j+1, r, c);
        dfs(grid, i,j-1, r, c);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    int r=-1;
                    int c=-1;
                    dfs(grid, i, j, r, c);
                    res.push_back({i, j, r, c});
                }
            }
        }
        return res;
    }
};
