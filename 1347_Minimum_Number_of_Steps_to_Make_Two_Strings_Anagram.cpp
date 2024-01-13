#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int minSteps(string s, string t) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        if(s.size()!=t.size()){
            return 0;
        }
        int c=0;
        int a[26]={0};
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a']++;
        }
        for(int i=0; i<t.size(); i++){
            a[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(a[i]>0){
                c=c+a[i];
            }
        }
        return c;
    }
};
