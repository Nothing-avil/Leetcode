#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int M = 1e9+7;
    int dp[100001][2][3];
    int solver(int nn, int ab, int l){
        if(ab >= 2 || l >= 3) {
            return 0;
        }

        if(nn == 0)
            return 1;
        
        if(dp[nn][ab][l] != -1) {
            return dp[nn][ab][l];
        }

        int A = solver(nn-1, ab+1, 0) % M;
        int L = solver(nn-1, ab, l+1) % M;
        int P = solver(nn-1, ab, 0) % M;

        return dp[nn][ab][l] = ((A + L) % M + P) % M;
    };
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solver(n,0,0);
    }
};
