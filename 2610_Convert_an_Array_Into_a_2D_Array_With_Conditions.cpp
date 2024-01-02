#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        vector<int> mp(n+1);
        vector<vector<int>> result;
        for(int &num : nums) {
            int freq = mp[num];
            if(freq == result.size()) {
                result.push_back({});
            }
            result[freq].push_back(num);
            mp[num]++;
        }
        return result;
    }
};
