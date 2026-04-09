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

    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long r = 1;
        while (b) {
            if (b & 1) r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;
        vector<vector<vector<int>>> diff(B);
        for (int k = 1; k < B; k++) {
            diff[k].resize(k);
            for (int r = 0; r < k; r++) {
                int len = (n - r + k - 1) / k;
                diff[k][r].assign(len + 1, 1);
            }
        }
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k < B) {
                int rem = l % k;

                int L = (l - rem) / k;
                int R = (r - rem) / k;

                diff[k][rem][L] = 1LL * diff[k][rem][L] * v % MOD;
                if (R + 1 < diff[k][rem].size()) {
                    long long inv = modPow(v, MOD - 2);
                    diff[k][rem][R + 1] = 1LL * diff[k][rem][R + 1] * inv % MOD;
                }
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (long long)nums[i] * v % MOD;
                }
            }
        }
        for (int k = 1; k < B; k++) {
            for (int r = 0; r < k; r++) {
                long long cur = 1;
                int len = diff[k][r].size() - 1;

                for (int j = 0; j < len; j++) {
                    cur = cur * diff[k][r][j] % MOD;
                    int idx = r + j * k;
                    if (idx < n) {
                        nums[idx] = (long long)nums[idx] * cur % MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};
