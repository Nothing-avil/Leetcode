#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")

class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        if(n==0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(n%2!=0){
            return false;
        }
        return (floor(log2(n))==ceil(log2(n)));
    }
};
