#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int x=0, j=1;
        int n= nums.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                res[x]=nums[i];
                x+=2;
            }
            else{
                res[j]= nums[i];
                j+=2;
            }
        }
        return res;
    }
};
