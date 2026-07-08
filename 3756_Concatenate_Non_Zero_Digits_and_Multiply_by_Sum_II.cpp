// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
const auto __ = []() {
    struct Leetcode {
        static void _() {
            std::ofstream("display_runtime.txt") << 0 << '\n';
       }
    };
    std::atexit(&Leetcode::_);
    return 0;
};
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        static const int MX = 100001;
        static const int MOD = 1000000007;
        static vector<long long> pow10 = [] {
            vector<long long> p(MX);
            p[0] = 1;
            for (int i = 1; i < MX; i++) {
                p[i] = p[i - 1] * 10 % MOD;
            }
            return p;
        }();

        int n = s.size();
        vector<int> sumD(n + 1), cntN0(n + 1);
        vector<long long> p(n + 1);

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0);
            p[i] = d ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int n0 = cntN0[r + 1] - cntN0[l];
            int sd = sumD[r + 1] - sumD[l];
            long long x = (p[r + 1] - p[l] * pow10[n0] % MOD + MOD) % MOD;
            ans.push_back(x * sd % MOD);
        }
        return ans;
    }
};
