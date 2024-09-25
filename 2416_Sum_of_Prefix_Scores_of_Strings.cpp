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
class Trie {
private:
    Trie* children[26]{};
    int cnt = 0;
public:
    void insert(string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            ++node->cnt;
        }
    }
    int search(string& w) {
        Trie* node = this;
        int ans = 0;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return ans;
            }
            node = node->children[idx];
            ans += node->cnt;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for (auto& w : words) {
            trie->insert(w);
        }
        vector<int> ans;
        for (auto& w : words) {
            ans.push_back(trie->search(w));
        }
        return ans;
    }
};
