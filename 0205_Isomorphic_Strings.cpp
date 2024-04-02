#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);            
    cout.tie(nullptr);           
    return 'c';                  
}();
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp1[256]{};
        int mp2[256]{};
        for (int i = 0; i < s.size(); ++i) {
            char a = s[i], b = t[i];
            if (mp1[a] != mp2[b]) {
                return false;
            }
            mp1[a] = mp2[b] = i + 1;
        }
        return true;
    }
};
