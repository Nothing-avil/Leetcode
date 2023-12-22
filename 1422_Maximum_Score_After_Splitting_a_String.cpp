#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int maxScore(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = s.length();
        int result = INT_MIN;
        int zeros = 0;
        int ones  = 0;
        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }   
            result = max(result, zeros - ones);
        }
        if(s[n-1] == '1') {
            ones++;
        }
        return result+ones;
    }
};
