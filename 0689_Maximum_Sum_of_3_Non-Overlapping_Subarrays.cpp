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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ans(3);
        int s = 0, s1 = 0, s2 = 0, s3 = 0;
        int mx1 = 0, mx12 = 0;
        int idx1 = 0, idx121 = 0, idx122 = 0;
        for (int i = k * 2; i < nums.size(); ++i) {
            s1 += nums[i - k * 2];
            s2 += nums[i - k];
            s3 += nums[i];
            if (i >= k * 3 - 1) {
                if (s1 > mx1) {
                    mx1 = s1;
                    idx1 = i - k * 3 + 1;
                }
                if (mx1 + s2 > mx12) {
                    mx12 = mx1 + s2;
                    idx121 = idx1;
                    idx122 = i - k * 2 + 1;
                }
                if (mx12 + s3 > s) {
                    s = mx12 + s3;
                    ans = {idx121, idx122, i - k + 1};
                }
                s1 -= nums[i - k * 3 + 1];
                s2 -= nums[i - k * 2 + 1];
                s3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};
