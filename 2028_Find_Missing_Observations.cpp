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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean*(n+rolls.size());
        int rollsum = accumulate(rolls.begin(), rolls.end(), 0);
        int diff= sum - rollsum;
        if(diff > n*6 || diff < n){
            return {};
        }
        vector<int> res(n, diff/n);
        int re= diff%n;
        for(int i=0; i<n; i++){
            res[i] += (i<re ? 1:0);
        }
        return res;
    }
};
/*
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res(n);
        int sum = mean*(n+rolls.size());
        int rollsum = accumulate(rolls.begin(), rolls.end(), 0);
        int diff= sum - rollsum;
        if(diff > n*6 || diff < n){
            return {};
        }
        int i=0;
        while(diff){
            res[i++]++;
            diff--;
            if(i>=n){
                i=0;
            }
        }
        return res;
    }
};
*/
