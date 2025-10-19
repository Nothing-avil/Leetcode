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
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q{{s}};
        unordered_set<string> vis{{s}};
        string ans = s;
        int n = s.size();
        while (!q.empty()) {
            s = q.front();
            q.pop();
            ans = min(ans, s);
            string t1 = s;
            for (int i = 1; i < n; i += 2) {
                t1[i] = (t1[i] - '0' + a) % 10 + '0';
            }
            string t2 = s.substr(n - b) + s.substr(0, n - b);
            for (auto& t : {t1, t2}) {
                if (!vis.count(t)) {
                    vis.insert(t);
                    q.emplace(t);
                }
            }
        }
        return ans;
    }
};
