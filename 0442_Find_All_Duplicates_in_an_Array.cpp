#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<int> res;
        std::bitset<100001> cache;
        for(int i=0;i<nums.size(); i++){
            bool c= cache.test(nums[i]);
            if(c){
                res.push_back(nums[i]);
            }
            else{
                cache.set(nums[i]);
            }
        }
        return res;
    }
};
