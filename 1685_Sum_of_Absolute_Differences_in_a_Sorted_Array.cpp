#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int sum= accumulate(begin(nums), end(nums),0);
        int n= nums.size();
        vector<int> res(n);
        int pre=0;
        for(int i=0; i<n; i++){
            int l=pre;

            res[i]= nums[i]*i - l + (sum-pre-nums[i]) - nums[i]*(n-i-1);
            pre+= nums[i];
        }
        return res;
    }
};
