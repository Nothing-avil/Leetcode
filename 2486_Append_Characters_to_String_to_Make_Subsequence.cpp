#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")

class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int n= s.size();
        int m= t.size();
        int i=0, j=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }
        return m-j;
    }
};
