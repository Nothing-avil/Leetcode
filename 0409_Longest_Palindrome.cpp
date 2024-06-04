#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int longestPalindrome(string s) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int ans=0;
        unordered_map<char, int> mp;
        for(char c:s){
            mp[c]++;
            if(mp[c]%2==0){
                ans+=2;
            }
        }
        for(auto i: mp){
            if(i.second%2!=0){
                ans++;
                break;
            }
        }
        return ans;
    }
};
