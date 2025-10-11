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
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for(int i: power){
            mp[i]++;
        }
        vector<int>sandy;
        for(auto i: mp){
            sandy.push_back(i.first);
        }
        sort(sandy.begin(), sandy.end());
        int n= sandy.size();
        if(n==1){
            return static_cast<long long>(sandy[0])*mp[sandy[0]];
        }
        vector<long long> good(n+1);
        for(int i=1; i<=n; i++){
            long long take= static_cast<long long>(sandy[i-1])*mp[sandy[i-1]];
            long long not_take= take;
            for (int j = i - 2; j >= 0; --j) {
                if (sandy[i - 1] - sandy[j] > 2) {
                    not_take += good[j + 1];
                    break;
                }
            }
            long long both = good[i - 1];
            good[i] = max(not_take, both);
        }
        return good[n];
    }
};
