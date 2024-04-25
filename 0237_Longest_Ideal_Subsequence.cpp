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
    int longestIdealString(string s, int k) {
        int n = s.size();
        int ans = 1;
        vector<int> dp(n, 1);
        unordered_map<char, int> d;
        d[s[0]] = 0;
        for (int i = 1; i < n; ++i) {
            char a = s[i];
            for (char b = 'a'; b <= 'z'; ++b) {
                if (abs(a - b) > k) continue;
                if (d.count(b)) dp[i] = max(dp[i], dp[d[b]] + 1);
            }
            d[a] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
