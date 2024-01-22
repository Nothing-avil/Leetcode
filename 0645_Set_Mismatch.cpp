#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        int s1 = (1 + n) * n / 2;
        int s2 = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for (int x : set) {
            s2 += x;
        }
        int s = accumulate(nums.begin(), nums.end(), 0);
        return {s - s2, s1 - s2};

    }
};
