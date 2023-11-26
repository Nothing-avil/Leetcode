#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= matrix.size();
        int m= matrix[0].size();
        int res=0;
        vector<pair<int, int>> ans;
        for(int r=0; r<n; r++){
            vector<pair<int, int>> curr;
            vector<bool> chesk(m, false);
            for(auto [h,c] : ans){
                if(matrix[r][c]==1){
                    curr.push_back({h+1,c});
                    chesk[c]= true;
                }
            }
            for(int co=0; co<m; co++) {
                if(chesk[co]==false && matrix[r][co] ==1){
                    curr.push_back({1,co});
                }
            }
            for(int i=0; i<curr.size(); i++){
                int b= curr[i].first;
                int x= i+1;
                res= max(res, b*x);  
            }
            ans=curr;
        }
        return res;
    }
};
