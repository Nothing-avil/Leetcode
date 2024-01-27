#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int mod= 1e9+7;
    int kInversePairs(int n, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int fin[k+1];
        int get[k+2];
        memset(fin, 0, sizeof(fin));
        fin[0]=1;
        fill(get, get+k+2, 1);
        get[0]=0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                fin[j] = (get[j + 1] - get[max(0, j - (i - 1))] + mod) % mod;
            }
            for (int j = 1; j <= k + 1; ++j) {
                get[j] = (get[j - 1] + fin[j - 1]) % mod;
            }
        }
        return fin[k];
    }
};
