#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = arr.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            int mx = 0;
            for (int j = i; j > max(0, i - k); --j) {
                mx = max(mx, arr[j - 1]);
                f[i] = max(f[i], f[j - 1] + mx * (i - j + 1));
            }
        }
        return f[n]; 
    }
};
