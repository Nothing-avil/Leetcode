#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int mod= 1e9+7;
    vector<vector<int>>adj ={
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };
    int knightDialer(int n) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int res=0;
        vector<vector<int>>dp(n,vector<int>(10));
        for(int i=0; i<=9;i++){
            dp[0][i]=1;
        }
        for(int i=1; i<n; i++){
            for(int c=0; c<10; c++){
                int ans=0;
                for(int &cell: adj[c]){
                    ans= (ans+dp[i-1][cell])%mod;
                }
                dp[i][c]=ans;
            }
        }
        for(int cell=0; cell<10; cell++){
            res= (res+dp[n-1][cell])%mod;
        }
        return res;
    }
};
