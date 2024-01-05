#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int len = 1;
            auto it = mp.upper_bound(nums[i]);
            if(it != mp.begin()) {
                it--;
                if(it->first < nums[i]) {
                    len += it->second;
                }
            }
            mp[nums[i]] = max(mp[nums[i]], len);
            it = mp.upper_bound(nums[i]);
            while(it != mp.end() && it->second <= len) {
                mp.erase(it++);
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
