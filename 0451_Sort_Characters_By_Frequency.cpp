#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    string frequencySort(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        using int_char=pair<int, char>;
        int freq[75];        
        for(char c : s)
            freq[c-'0']++;

        vector<int_char> freq_c;
        for(char c='0'; c<='z'; c++){
            if (freq[c-'0']==0) continue;
            freq_c.emplace_back(freq[c-'0'], c);
        }
        sort(freq_c.begin(), freq_c.end(), greater<int_char>());
        string ans;
        for (auto& [n, c]: freq_c){
            ans+=string(n, c);
        }
        return ans;   
    }
};
