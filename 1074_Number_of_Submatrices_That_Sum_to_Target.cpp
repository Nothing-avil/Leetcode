#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int m = matrix.size(), 
            n = matrix[0].size(),
            res = 0;
        for(int l = 0; l < n; ++l){
            int sums[105] = { 0 };
            for(int r = l; r < n; ++r){
                for(int i = 0; i < m; ++i){
                    sums[i] += matrix[i][r];
                }
                for(int i = 0; i < m; ++i){
                    int sum = 0;
                    for(int j = i; j < m; ++j){
                        sum += sums[j];
                        if(sum == target){
                            ++res;
                        }
                    }
                }
            }
        }
        return res;
    }
};
