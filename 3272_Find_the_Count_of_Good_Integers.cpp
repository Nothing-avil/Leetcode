// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<vector<long long>> temp = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 9, 4, 3, 2, 1, 1, 1, 1, 1}, {0, 9, 4, 3, 2, 1, 1, 1, 1, 1}, {0, 243, 108, 69, 54, 27, 30, 33, 27, 23}, {0, 252, 172, 84, 98, 52, 58, 76, 52, 28}};
        if(n < 5){
            return temp[n][k];
        }
        vector<long long> fac(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * i;
        }

        long long ans = 0;
        unordered_set<string> vis;
        int base = pow(10, (n - 1) / 2);

        for (int i = base; i < base * 10; ++i) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            s += rev.substr(n % 2);
            if (stoll(s) % k) {
                continue;
            }
            string t = s;
            sort(t.begin(), t.end());
            if (vis.count(t)) {
                continue;
            }
            vis.insert(t);
            vector<int> cnt(10);
            for (char c : t) {
                cnt[c - '0']++;
            }
            long long res = (n - cnt[0]) * fac[n - 1];
            for (int x : cnt) {
                res /= fac[x];
            }
            ans += res;
        }
        return ans;
    }
};
