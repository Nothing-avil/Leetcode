#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=s.size();
        int i=0, j=n-1;
        int c=0;
        while(i<j && s[i]==s[j]){
            char ch=s[i];
            while(i<j && s[i]==ch){
                i++;
            }
            while(j>=i && s[j]==ch){
                j--;
            }
        }
        return j-i+1;
    }
};
