class Solution {
public:
    vector<int>res;
    void dfs(int a, int min, unordered_map<int, vector<int>>& dp){
        res.push_back(a);
        for(int &it: dp[a]){
            if(min!=it){
                dfs(it, a, dp);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
        unordered_map<int, vector<int>> dp;
        int a=-1;
        for(auto &t: adjacentPairs){
            dp[t[0]].push_back(t[1]);
            dp[t[1]].push_back(t[0]);
        }
        for(auto &s: dp){
            if(s.second.size()==1){
                a=s.first;
                break;
            }
        }
        dfs(a, INT_MIN, dp);
        return res;
    }
};
