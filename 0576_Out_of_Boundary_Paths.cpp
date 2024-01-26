#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int mod= 1e9+7;
    int m, n;
    int dp[51][51][51];
    int dir[5]= {-1, 0, 1, 0, -1};
    int solve(int r, int c, int move){
        if(r<0 || r>=m || c<0 || c>=n){
            return 1;
        }
        if(move==0){
            return 0;
        }
        if(dp[r][c][move]!=-1){
            return dp[r][c][move];
        }
        int res=0;
        for(int i=0; i<4; i++){
            int x= r+ dir[i];
            int y= c+ dir[i+1];
            res+= solve(x, y, move-1);
            res%= mod;
        }
        return dp[r][c][move]=res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        memset(dp, -1, sizeof(dp));
        this->m=m;
        this->n=n;
        return solve(startRow, startColumn, maxMove);
    }
};
