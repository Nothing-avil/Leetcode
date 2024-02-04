#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int m = t.length();
        int n = s.length();
        vector<int> mp(128,0);
        int counter = m, start = 0;
        int minLength = INT_MAX;
        int minStart;

        for(int i=0; i<m; i++){
            mp[t[i]-'A']++;
        }

        for(int end=0; end<n; end++){
            mp[s[end]-'A']--;
            if(mp[s[end]-'A']>=0) counter--;

            while(counter==0){
                if(end-start+1<minLength){
                    minStart = start;
                    minLength = end-start+1;
                }
                mp[s[start]-'A']++;
                if(mp[s[start]-'A']>0) counter++;
                start++;
            }
        }
        return minLength==INT_MAX ? "" : s.substr(minStart, minLength);
    }
};
