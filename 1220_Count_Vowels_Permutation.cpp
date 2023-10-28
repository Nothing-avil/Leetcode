class Solution {
public:
    int M= 1e9+7;
    int a=0, e=1, I=2, o=3, u=4;
    int countVowelPermutation(int n) {
        long long dp[5][n+1];
        for(int i=0; i<=4; i++){
            dp[i][1]=1;
        }
        for(int i=2; i<=n; i++){
            dp[a][i]= (dp[e][i-1] + dp[I][i-1] + dp[u][i-1])%M;
            dp[e][i]= (dp[a][i-1] + dp[I][i-1])%M;
            dp[I][i]= (dp[e][i-1] + dp[o][i-1])%M;
            dp[o][i]= (dp[I][i-1])%M;
            dp[u][i]= (dp[I][i-1] + dp[o][i-1])%M;
        }
        long long result=0;
        for(int i=0; i<=4; i++){
            result =( result+dp[i][n])%M;
        }
        return result;
    }
};
