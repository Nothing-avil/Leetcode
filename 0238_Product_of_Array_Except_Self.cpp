#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= nums.size();
        vector<int> res(n);
        int x=1;
        for(int i=0; i<n; i++){
            res[i]= x;
            x*= nums[i];
        }
        int r=1;
        for(int i=n-1; i>=0; i--){
            res[i]*=r;
            r*=nums[i];
        }
        return res;
    }
};
