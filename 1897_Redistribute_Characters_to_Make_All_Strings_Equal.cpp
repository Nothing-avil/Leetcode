#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = words.size();
        int count[26] = {0};
        for(string &word : words) {
            for(char &ch : word) {
                count[ch-'a']++;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(count[i]%n != 0) {
                return false;
            }
        }
        return true;
    }
};
