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
    bool exists (string sub, vector<string>& dictionary) {
        for (int i=0; i<dictionary.size(); i++) {
            if (dictionary[i]==sub) return true;
        }

        return false;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int index = 0;
        vector <int> dp (s.length()+1, 0);
        dp[s.length()] = 0;

        for (int index = s.length()-1; index>=0; index--) {
            int minAns = INT_MAX;
            for (int i = index; i < s.length(); i++) {
                string sub = s.substr(index, i - index + 1);
                int small = sub.length();
                if (exists(sub, dictionary)) {
                    small = 0;
                }
                int ans2 = dp[i+1];
                minAns = min (minAns, small + ans2);
            }
            dp[index] = minAns;
        }
        return dp[0];
    }
};
