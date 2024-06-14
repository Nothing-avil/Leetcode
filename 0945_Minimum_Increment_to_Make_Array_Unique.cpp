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
    int minIncrementForUnique(vector<int>& nums) {
        int sandy = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                sandy += (abs(nums[i] - nums[i + 1]) + 1);
                nums[i + 1] += abs(nums[i] - nums[i + 1]) + 1;
            }
        }
        return sandy;
    }
};
