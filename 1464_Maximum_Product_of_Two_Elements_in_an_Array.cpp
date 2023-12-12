#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= nums.size();
        int lar=0, seclar=0;
        for(int i=0; i<n; i++){
            if(lar<nums[i]){
                seclar=lar;
                lar= nums[i];
            }
            else{
                seclar=max(seclar, nums[i]);
            }
        }
        return (lar-1)*(seclar-1);
    }
};
