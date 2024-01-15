#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& M) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=M.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[M[i][1]]++;
        }
        vector<int>ans, res;
        for(auto& it: mp){
            if(it.second==1){
                res.push_back(it.first);
            }
        }
        for(int i=0; i<n; i++){
            if(mp.find(M[i][0])==mp.end()){
                ans.push_back(M[i][0]);
                mp[M[i][0]]++;
            }
        }
        sort(ans.begin(), ans.end());
        sort(res.begin(), res.end());
        return {ans, res};
    }
};
