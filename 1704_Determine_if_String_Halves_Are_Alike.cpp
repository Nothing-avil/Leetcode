#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= s.size();
        if(n%2!=0){
            return 0;
        }
        int c=0, d=0;
        for(int i=0; i<n/2; i++){
            if(isvowel(s[i])){
                c++;
            }
        }
        for(int i=n/2; i<n; i++){
            if(isvowel(s[i])){
                d++;
            }
        }
        return c==d;
    }
};
