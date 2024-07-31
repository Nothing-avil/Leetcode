// ██╗  ██╗███████╗██╗     ██╗      ██████╗
// ██║  ██║██╔════╝██║     ██║     ██╔═══██╗
// ███████║█████╗  ██║     ██║     ██║   ██║
// ██╔══██║██╔══╝  ██║     ██║     ██║   ██║
// ██║  ██║███████╗███████╗███████╗╚██████╔╝▄█╗
// ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ ╚═════╝ ╚═╝
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
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int w = books[i - 1][0], h = books[i - 1][1];
            f[i] = f[i - 1] + h;
            for (int j = i - 1; j > 0; --j) {
                w += books[j - 1][0];
                if (w > shelfWidth) {
                    break;
                }
                h = max(h, books[j - 1][1]);
                f[i] = min(f[i], f[j - 1] + h);
            }
        }
        return f[n];
    }
};
