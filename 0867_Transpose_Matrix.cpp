#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=matrix.size();
        int m= matrix[0].size();
        vector<vector<int>>vec(m, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vec[j][i]= matrix[i][j];
            }
        }
        return vec;
    }
};
