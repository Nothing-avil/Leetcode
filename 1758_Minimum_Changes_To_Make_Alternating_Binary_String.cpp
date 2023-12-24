#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int minOperations(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = s.length();
        int start_with_0 = 0;
        for(int i = 0; i<n; i++) {
            if(i%2 == 0) {
                if(s[i] == '1') {
                    start_with_0++;
                }
            } else {
                if(s[i] == '0') {
                    start_with_0++;
                }
            }
        }
        
        return min(start_with_0, n - start_with_0);
    }
};
