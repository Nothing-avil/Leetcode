#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        map<int , int>m;
        int c= 0;
        int max = 0;
        for(int i = 0; i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>max){
                max=m[nums[i]];
                c=0;
            }
            if(m[nums[i]]==max)
                c++;
        }
        return c*max;
    }
};
