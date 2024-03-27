#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int res=0;
        int i=0, j=0;
        int prod=1;
        while(i<nums.size()){
            prod *= nums[i];
            while(j<=i && prod>=k){
                prod/=nums[j++];
            }
            res+=i-j+1;
            i++;
        }
        return res;
    }
};
