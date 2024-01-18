#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int climbStairs(int n) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        if(n==1){
            return 1;
        }
        int a=0, b=1,c=0;
        while(n--){
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};
