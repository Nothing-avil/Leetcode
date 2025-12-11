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
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> g1;
        unordered_map<int, vector<int>> g2;
        for (const auto& building : buildings) {
            int x = building[0], y = building[1];
            g1[x].push_back(y);
            g2[y].push_back(x);
        }
        for (auto& e : g1) {
            sort(e.second.begin(), e.second.end());
        }
        for (auto& e : g2) {
            sort(e.second.begin(), e.second.end());
        }
        int ans = 0;
        for (const auto& building : buildings) {
            int x = building[0], y = building[1];
            const vector<int>& l1 = g1[x];
            const vector<int>& l2 = g2[y];
            if (l2[0] < x && x < l2[l2.size() - 1] && l1[0] < y && y < l1[l1.size() - 1]) {
                ans++;
            }
        }
        return ans;
    }
};
