// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int numberOfWays(int n, int x) {
        const int mod = 1e9 + 7;
        int dp[301][301];
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> solve = [&](int nn, int num){
            if(nn == 0){
                return 1;
            }
            if(nn < 0){
                return 0;
            }
            int k = pow(num, x);
            if(k > nn){
                return 0;
            }
            if(dp[nn][num] != -1){
                return dp[nn][num];
            }
            int take = (solve((nn - k), num + 1)) % mod;
            int ntake = (solve(nn, num + 1))% mod;
            return dp[nn][num] = (take + ntake) % mod;
        };
        solve(n, 1);
        return dp[n][1];
    }
};
