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
    int maxDifference(string s, int k) {
        const int n = s.size();
        const int inf = INT_MAX / 2;
        int ans = -inf;
        for (int a = 0; a < 5; ++a) {
            for (int b = 0; b < 5; ++b) {
                if (a == b) {
                    continue;
                }
                int curA = 0, curB = 0;
                int preA = 0, preB = 0;
                int t[2][2] = {{inf, inf}, {inf, inf}};
                int l = -1;
                for (int r = 0; r < n; ++r) {
                    curA += (s[r] == '0' + a);
                    curB += (s[r] == '0' + b);
                    while (r - l >= k && curB - preB >= 2) {
                        t[preA & 1][preB & 1] = min(t[preA & 1][preB & 1], preA - preB);
                        ++l;
                        preA += (s[l] == '0' + a);
                        preB += (s[l] == '0' + b);
                    }
                    ans = max(ans, curA - curB - t[(curA & 1) ^ 1][curB & 1]);
                }
            }
        }
        return ans;
    }
};
