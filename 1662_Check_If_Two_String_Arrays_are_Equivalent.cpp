#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=word1.size(), ci=0;
        int m= word2.size(), cj=0;
        int i=0, j=0;
        while(ci<n && cj<m){
            if(word1[ci][i]!= word2[cj][j]){
                return false;
            }
            i++;
            j++;
            if(j==word2[cj].size()){
                j=0;
                cj++;
            }
            if(i==word1[ci].size()){
                i=0;
                ci++;
            }
        }
        if(ci==n && cj==m){
            return true;
        }
        return false;
    }
};
