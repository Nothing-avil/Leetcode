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
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> purana(n);
        for(int i=0; i<n; i++){
            purana[i] = points[0][i];
        }
        for(int i=1; i<m; i++){
            vector<long long> left(n);
            vector<long long> right(n);
            left[0]=purana[0];
            for(int j=1; j<n; j++){
                left[j] = max(purana[j], left[j-1]-1);
            }
            right[n-1]=purana[n-1];
            for(int j=n-2; j>=0; j--){
                right[j] = max(purana[j], right[j+1]-1);
            }
            vector<long long> res(n);
            for(int j=0; j<n; j++){
                res[j] = points[i][j] + max(right[j], left[j]);
            }
            purana= res;
        }
        return *max_element(purana.begin(), purana.end());
    }
};
