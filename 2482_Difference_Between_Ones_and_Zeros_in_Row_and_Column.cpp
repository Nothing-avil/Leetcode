#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> rowOnes(m, 0);
        vector<int> colOnes(n, 0);
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 1) {
                    rowOnes[i]++;
                    colOnes[j]++;
                } 
            }
        }
        
        vector<vector<int>> diff(m, vector<int>(n, 0));
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int onesRowi = rowOnes[i];
                int onesColj = colOnes[j];
                
                int zerosRowi = n-onesRowi;
                int zerosColj = m-onesColj;
                
                diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
            }
        }
        
        return diff;
    }
};
