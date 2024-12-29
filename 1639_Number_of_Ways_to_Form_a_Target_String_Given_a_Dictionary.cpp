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
    int numWays(vector<string>& words, string target) {
        int mod = 1e9+7;
        int n= words.size();
        int m = words[0].size();
        int k = target.size();
        vector<vector<long long>> freq(26, vector<long long>(m));
        for(int i=0; i<m; i++){
            for(string s: words){
                char  ch = s[i];
                freq[ch - 'a'][i]++;
            }
        }
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        fill(dp[0], dp[0] + m + 1, 1);
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] =( dp[i][j - 1] + dp[i - 1][j - 1] * freq[target[i - 1] - 'a'][j - 1])%mod;
                dp[i][j] %= mod;
            }
        }
        return dp[k][m];
    }
};
