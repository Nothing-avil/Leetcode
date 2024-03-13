#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int pivotInteger(int n) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int x= n*(n+1)/2;
        int srt= sqrt(x);

        return (srt*srt==x)?srt:-1;
    }
};
