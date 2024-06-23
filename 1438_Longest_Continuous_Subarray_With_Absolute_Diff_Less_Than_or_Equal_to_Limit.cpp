#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int ans = 0, j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[j++]));
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
