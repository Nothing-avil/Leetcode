#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int longestCommonSubsequence(string S1, string S2) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = S1.length();
        int m= S2.length();
        int LCS_table[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
              if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
              else if (S1[i - 1] == S2[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
              else
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
            }
        }
        return LCS_table[n][m];
    }
};
