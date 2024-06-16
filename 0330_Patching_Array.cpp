#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long ans=0;
        int ptch=0, i=0;
        while(ans<n){
            if(i<nums.size() && nums[i]<= (ans+1)){
                ans+=nums[i];
                i++;
            }
            else{
                ans+= (ans+1);
                ptch++;
            }
        }
        return ptch;
    }
};
