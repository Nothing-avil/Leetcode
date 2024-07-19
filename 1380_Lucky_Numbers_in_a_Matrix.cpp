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
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        int row=INT_MIN, col=INT_MAX;;
        for(int i=0; i<n; i++){
            int temp=INT_MAX;
            for(int j=0; j<m; j++){
                temp = min(temp, matrix[i][j]);
            }
            row = max(row, temp);
        }
        for(int i=0; i<m; i++){
            int temp=INT_MIN;
            for(int j=0; j<n; j++){
                temp = max(temp, matrix[j][i]);
            }
            col = min(col, temp);
        }
        if(row==col){
            return {row};
        }
        return {};
    }
};
