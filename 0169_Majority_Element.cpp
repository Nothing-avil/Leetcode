#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=0;
        int c=0;
        for(int num: nums){
            if(c==0){
                n=num;
                c++;
            }
            else if(n==num){
                c++;
            }
            else{
                c--;
            }
        }
        return n;
    }
};
