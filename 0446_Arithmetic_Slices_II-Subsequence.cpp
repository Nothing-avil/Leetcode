#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        int result = 0;
        unordered_map<long, int> mp[n];
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                auto diff = (long)nums[i]-nums[j];
                auto it = mp[j].find(diff);
                int count_at_j = it==end(mp[j]) ? 0 : it->second;
                mp[i][diff] += count_at_j+1;
                result      += count_at_j;
            }
        }
        return result;
    }
};
