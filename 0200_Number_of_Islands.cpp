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
    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col){
        
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] != '1')
            return;
        
        grid[i][j]='0';

        dfs(grid, i+1,j, row, col);
        dfs(grid, i-1,j, row, col);
        dfs(grid, i,j+1, row, col);
        dfs(grid, i,j-1, row, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        int row=grid.size(), col=grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    c++;
                    dfs(grid, i, j, row, col);
                }
            }
        }
        return c;
    }
};
