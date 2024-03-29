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
    long long countSubarrays(vector<int>& nums, int k) {

        long long count=0;
        int maxs= *max_element(nums.begin(), nums.end());
        int i=0, j=0;
        int c=0;
        while(i<nums.size()){
            if(nums[i]==maxs){
                c++;
            }
            while(c>=k){
                if(nums[j++]==maxs){
                    c--;
                }
                count+=(nums.size()-i);
            }
            i++;
        }
        return count;
    }
};
