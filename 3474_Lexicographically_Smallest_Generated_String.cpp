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
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, 'a');
        vector<bool> fixed(n + m - 1, false);
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') continue;
            for (int j = 0; j < m; j++) {
                int k = i + j;
                if (fixed[k] && ans[k] != t[j]) return "";
                ans[k] = t[j];
                fixed[k] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') continue;
            bool same = true;
            for (int j = 0; j < m; j++) {
                if (ans[i + j] != t[j]) {
                    same = false;
                    break;
                }
            }
            if (!same) continue;
            bool ok = false;
            for (int j = i + m - 1; j >= i; j--) {
                if (!fixed[j]) {
                    ans[j] = 'b';
                    ok = true;
                    break;
                }
            }
            if (!ok) return "";
        }
        return ans;
    }
};
