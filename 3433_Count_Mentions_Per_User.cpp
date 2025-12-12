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
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        ranges::sort(events, [](const vector<string>& a, const vector<string>& b) {
            int x = stoi(a[1]);
            int y = stoi(b[1]);
            if (x == y) {
                return a[0][2] < b[0][2];
            }
            return x < y;
        });

        vector<int> ans(numberOfUsers, 0);
        vector<int> onlineT(numberOfUsers, 0);
        int lazy = 0;

        for (const auto& e : events) {
            string etype = e[0];
            int cur = stoi(e[1]);
            string s = e[2];

            if (etype[0] == 'O') {
                onlineT[stoi(s)] = cur + 60;
            } else if (s[0] == 'A') {
                lazy++;
            } else if (s[0] == 'H') {
                for (int i = 0; i < numberOfUsers; ++i) {
                    if (onlineT[i] <= cur) {
                        ++ans[i];
                    }
                }
            } else {
                stringstream ss(s);
                string token;
                while (ss >> token) {
                    ans[stoi(token.substr(2))]++;
                }
            }
        }

        if (lazy > 0) {
            for (int i = 0; i < numberOfUsers; ++i) {
                ans[i] += lazy;
            }
        }

        return ans;
    }
};
