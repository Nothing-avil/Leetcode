// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#include <ranges>
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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
       int l = 1, r = cells.size();
        int g[row][col];
        int dirs[5] = {0, 1, 0, -1, 0};
        auto check = [&](int k) -> bool {
            memset(g, 0, sizeof(g));
            for (int i = 0; i < k; ++i) {
                g[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }
            queue<pair<int, int>> q;
            for (int j = 0; j < col; ++j) {
                if (g[0][j] == 0) {
                    q.emplace(0, j);
                    g[0][j] = 1;
                }
            }
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x == row - 1) {
                    return true;
                }
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dirs[i];
                    int ny = y + dirs[i + 1];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0) {
                        q.emplace(nx, ny);
                        g[nx][ny] = 1;
                    }
                }
            }
            return false;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
