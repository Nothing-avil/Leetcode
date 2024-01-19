#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=matrix.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            vector<int> ans=res;
            for(int j=0; j<n; j++){
                if(j){
                    ans[j]=min(ans[j], res[j-1]);
                }
                if(j+1<n){
                    ans[j]=min(ans[j], res[j+1]);
                }
                ans[j]+=matrix[i][j];
            }
            res=ans;
        }
        return *min_element(res.begin(), res.end());
    }
};
