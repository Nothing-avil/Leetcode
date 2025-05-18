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
    int colorTheGrid(int m, int n) {
        auto f1 = [&](int x) {
            int last = -1;
            for (int i = 0; i < m; ++i) {
                if (x % 3 == last) {
                    return false;
                }
                last = x % 3;
                x /= 3;
            }
            return true;
        };
        auto f2 = [&](int x, int y) {
            for (int i = 0; i < m; ++i) {
                if (x % 3 == y % 3) {
                    return false;
                }
                x /= 3;
                y /= 3;
            }
            return true;
        };

        const int mod = 1e9 + 7;
        int mx = pow(3, m);
        unordered_set<int> valid;
        vector<int> f(mx);
        for (int i = 0; i < mx; ++i) {
            if (f1(i)) {
                valid.insert(i);
                f[i] = 1;
            }
        }
        unordered_map<int, vector<int>> d;
        for (int i : valid) {
            for (int j : valid) {
                if (f2(i, j)) {
                    d[i].push_back(j);
                }
            }
        }
        for (int k = 1; k < n; ++k) {
            vector<int> g(mx);
            for (int i : valid) {
                for (int j : d[i]) {
                    g[i] = (g[i] + f[j]) % mod;
                }
            }
            f = move(g);
        }
        int ans = 0;
        for (int x : f) {
            ans = (ans + x) % mod;
        }
        return ans;
    }
};
