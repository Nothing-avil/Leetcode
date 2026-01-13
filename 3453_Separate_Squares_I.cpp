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
    vector<vector<int>>* squares;
    double s;

    bool check(double y1) {
        double t = 0.0;
        for (const auto& a : *squares) {
            int y = a[1];
            int l = a[2];
            if (y < y1) {
                t += (double) l * min(y1 - y, (double) l);
            }
        }
        return t >= s / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        this->squares = &squares;
        s = 0.0;
        double l = 0.0;
        double r = 0.0;
        for (const auto& a : squares) {
            s += (double) a[2] * a[2];
            r = max(r, (double) a[1] + a[2]);
        }
        const double eps = 1e-5;
        while (r - l > eps) {
            double mid = (l + r) / 2.0;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
