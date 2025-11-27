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
#define func(i, a, b) for (int i=a; i<b; ++i)
#define MMD(A, B) ((A)% (B) +(B)) % (B)
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        long long sums = 0;
        vector<long long> pre(k, LLONG_MAX);
        pre[0] = 0;
        long long res= LLONG_MIN;
        func(i, 1, n+1){
            sums += nums[i-1];
            if(pre[MMD(i, k)] != LLONG_MAX){
                long long temp = sums - pre[MMD(i, k)];
                res = max(res, temp);
            }
            pre[MMD(i, k)]= min(pre[MMD(i, k)], sums);
        }
        return res;
    }
};
