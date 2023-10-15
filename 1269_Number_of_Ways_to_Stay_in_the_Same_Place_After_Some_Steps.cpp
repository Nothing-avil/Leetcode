class Solution {
public:
    int mod= 1e9+7;
    int n;
    int dp[501][501];
    int ARRAY(int i, int s){
        if(i<0 || i>=n){
            return 0;
        }
        if(s==0){
            if(i==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][s]!=-1){
            return dp[i][s];
        }
        int r = ARRAY(i+1, s-1)%mod;
        r = (r+ ARRAY(i-1, s-1))%mod;
        r = (r+ ARRAY(i, s-1))%mod;

        return dp[i][s]= r;
    }
    int numWays(int steps, int arrLen) {
        n=  min(steps, arrLen);
        memset(dp, -1, sizeof(dp));
        return ARRAY(0, steps);
    }
};
