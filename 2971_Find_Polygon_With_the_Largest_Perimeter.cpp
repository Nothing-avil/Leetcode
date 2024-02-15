#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cout.tie(nullptr), cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> s(n + 1);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        long long ans = -1;
        for (int k = 3; k <= n; ++k) {
            if (s[k - 1] > nums[k - 1]) {
                ans = max(ans, s[k]);
            }
        }
        return ans;
    }
};
