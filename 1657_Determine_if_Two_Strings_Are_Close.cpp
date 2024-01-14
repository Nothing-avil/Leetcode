#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        if(word1.size()!=word2.size()){
            return false;
        }
        vector<int>mp1(26);
        vector<int>mp2(26);
        for(int i=0; i<word1.size(); i++){
            mp1[word1[i]-'a']++;
            mp2[word2[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(mp1[i]!=0 && mp2[i]==0){
                return false;
            }
            if(mp1[i]==0 && mp2[i]!=0){
                return false;
            }
        }
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        return mp1==mp2;
    }
};
