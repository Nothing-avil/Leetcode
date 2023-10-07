class Solution {
public:
int dp[51][51][101];
int mod= 1e9+7;
int n, m, k;
int sol(int i, int cost, int maxfar){
    if(i==n){
        if(cost==k){
            return 1;
        }
        return 0;
    }

    if(dp[i][cost][maxfar]!=-1){
        return dp[i][cost][maxfar];
    }
    int res=0;
    for(int j=1; j<=m; j++){
        if(j>maxfar){
            res = (res + sol(i+1, cost+1, j))%mod;
        }
        else{
           res = (res + sol(i+1, cost, maxfar))%mod;
        }
    }
    return dp[i][cost][maxfar] = res%mod;
}
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        this->n=n;
        this->m=m;
        this->k=k;
        return sol(0, 0, 0);
    }
};
