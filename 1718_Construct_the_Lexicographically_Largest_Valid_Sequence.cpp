// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
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
    bool solve(int i, int n, vector<int>& res, vector<bool>& path){
        if(i >= res.size()){
            return true;
        }
        if(res[i] != -1){
            return solve(i+1, n, res, path);
        }
        for(int nn = n; nn>=1; nn--){
            if(path[nn]){
                continue;
            }
            path[nn] = true;
            res[i] = nn;
            if(nn == 1){
                if(solve(i+1, n, res, path) == true){
                    return true;
                }
            }
            else{
                int val = res[i] + i;
                if(val < res.size() && res[val] == -1){
                    res[val] = nn;
                    if(solve(i+1, n, res, path) == true){
                        return true;
                    }
                    res[val] = -1;
                }
            }
            path[nn] = false;
            res[i] = -1;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2*n-1, -1);
        vector<bool> path(n+1, false);
        solve(0, n, res, path);
        return res;
    }
};
