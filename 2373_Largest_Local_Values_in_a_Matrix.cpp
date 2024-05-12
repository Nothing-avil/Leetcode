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
    int find(vector<vector<int>>& grid, int k, int s){
        int max = grid[k][s];
        for(int i=k; i<k+3; i++){
            for(int j=s; j<s+3; j++){
                if(max<grid[i][j]){
                    max= grid[i][j];
                }
            }
        }
        return max;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<vector<int>> max(n-2, vector<int>(n-2, 0));
        for(int k=0; k<n-2; k++){
            for(int s=0; s<n-2; s++){
                max[k][s]= find(grid, k, s);
            }
        }
        return max;
    }
};
