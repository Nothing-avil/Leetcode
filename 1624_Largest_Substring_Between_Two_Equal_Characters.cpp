#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = s.length();
        vector<int> count(26, -1);
        
        int result = -1;
        
        for(int i = 0 ; i < n;  i++) {
            char ch = s[i];
            
            if(count[ch-'a'] == -1) {
                count[ch-'a'] = i;
            } else {
                result = max(result, i - count[ch-'a'] - 1);
            }
        }
        return result;
    }
};
