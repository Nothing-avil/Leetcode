#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    string customSortString(string order, string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int arr[26]={0};
        string str="";
        for(char ch:s){
            arr[ch-'a']++;
        }
        for(char ch:order){
            while(arr[ch-'a']-- >0){
                str+=ch;
            }
        }
        for(int i=0; i<26; i++){
            if(arr[i]>0){
                str+=string(arr[i],i+'a');
            }
        }
        return str;
    }
};
