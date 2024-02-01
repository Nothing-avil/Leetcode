#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i+=3){
            if(nums[i+2]-nums[i]<=k){
                res.push_back({nums[i], nums[i+1], nums[i+2]});
            }else{
                return {};
            }
        }
        return res;
    }
};
