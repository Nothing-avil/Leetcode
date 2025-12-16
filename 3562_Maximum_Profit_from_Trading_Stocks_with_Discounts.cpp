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
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> g(n + 1);
        for (auto& e : hierarchy) {
            g[e[0]].push_back(e[1]);
        }

        auto dfs = [&](const auto& dfs, int u) -> vector<array<int, 2>> {
            vector<array<int, 2>> nxt(budget + 1);
            for (int j = 0; j <= budget; j++) nxt[j] = {0, 0};

            for (int v : g[u]) {
                auto fv = dfs(dfs, v);
                for (int j = budget; j >= 0; j--) {
                    for (int jv = 0; jv <= j; jv++) {
                        for (int pre = 0; pre < 2; pre++) {
                            int val = nxt[j - jv][pre] + fv[jv][pre];
                            if (val > nxt[j][pre]) {
                                nxt[j][pre] = val;
                            }
                        }
                    }
                }
            }

            vector<array<int, 2>> f(budget + 1);
            int price = future[u - 1];

            for (int j = 0; j <= budget; j++) {
                for (int pre = 0; pre < 2; pre++) {
                    int cost = present[u - 1] / (pre + 1);
                    if (j >= cost) {
                        f[j][pre] = max(nxt[j][0], nxt[j - cost][1] + (price - cost));
                    } else {
                        f[j][pre] = nxt[j][0];
                    }
                }
            }

            return f;
        };

        return dfs(dfs, 1)[budget][0];
    }
};
