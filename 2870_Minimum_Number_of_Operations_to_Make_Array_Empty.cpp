#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int minOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int result = 0;
        for(auto &it : mp) {
            int freq = it.second;   
            if(freq == 1) {
                return -1;
            }
            result += ceil((double)freq/3);
        }
        return result;
    }
};
