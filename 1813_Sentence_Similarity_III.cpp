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
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream qwerty(sentence1);
        stringstream seco(sentence2);
        vector<string> v1, v2;
        string t = "";
        while(qwerty >> t){
            v1.push_back(t);
        }
        while(seco >> t){
            v2.push_back(t);
        }
        if (v1.size() < v2.size()) {
            swap(v1, v2);
        }
        int m = v1.size(), n = v2.size();
        int i = 0, j = 0;
        while (i < n && v1[i] == v2[i]) {
            ++i;
        }
        while (j < n && v1[m - 1 - j] == v2[n - 1 - j]) {
            ++j;
        }
        return i + j >= n;
    }
};
