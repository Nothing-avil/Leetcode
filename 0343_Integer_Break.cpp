class Solution {
public:
    int dp[59];
    int sol(int n) {
        int res= INT_MIN;
        if(n<=3){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i=2; i<n; i++){
            res = max(res, i* sol(n-i));
        }
        return dp[n]=res;
    }
    int integerBreak(int n) {
        if(n<=3){
            return n-1;
        }
        memset(dp, -1, sizeof(dp));
        return sol(n);
    }
};
