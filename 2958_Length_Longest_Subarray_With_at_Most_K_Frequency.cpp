#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int res=0;
        int i=0, j=0;
        unordered_map<int, int> mp;
        while(i<nums.size()){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[j++]]--;
            }
            res= max(res, i-j+1);
            i++;
        }
        return res;
    }
};
