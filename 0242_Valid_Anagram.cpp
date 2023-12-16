#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= s.size();
        int m= t.size();
        if(n!=m){
            return false;
        }
        int num[27]={0};
        for(int i=0; i<n; i++){
            num[s[i]-'a']++;
        }
        for(int i=0; i<m; i++){
            if(num[t[i]-'a']==0){
                return false;
            }
            num[t[i]-'a']--;
        }
        return true;
    }
};
