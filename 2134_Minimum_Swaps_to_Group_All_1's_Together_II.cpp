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
    int minSwaps(vector<int>& nums) {
        int c;
        int val= accumulate(nums.begin(), nums.end(), 0);
        int windo= accumulate(nums.begin(), nums.begin()+val, 0);
        c=windo;
        int tol= nums.size();
        for(int i=val; i<tol+val; i++){
            windo += nums[i%tol] - nums[(i-val+tol)%tol];
            c= max(c, windo);
        }
        return val-c;
    }
};
