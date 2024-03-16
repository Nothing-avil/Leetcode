#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        unordered_map<int,int> mp;
        int s = 0, ans = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i] == 1 ? 1 : -1;
            if (mp.count(s))
                ans = max(ans, i - mp[s]);
            else
                mp[s] = i;
        }
        return ans;
    }
};
