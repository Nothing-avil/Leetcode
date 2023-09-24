class Solution {
public:
    double champagneTower(int p, int r, int g) {
        vector<vector<double>> dp(r+2,vector<double>(r+2,0));
        dp[0][0]=p;
        for(int i=0;i<=r;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]>1){
                    dp[i+1][j]+=(dp[i][j]-1)/2;
                    dp[i+1][j+1]+=(dp[i][j]-1)/2;
                    dp[i][j]=1;
                }
            }
        }
        return dp[r][g];
    }
};
