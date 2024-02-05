#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int arr[26]={0};
        for(char ch: s){
            ++arr[ch-'a'];
        }
        for(int i=0; i<s.size(); i++){
            if(arr[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};
