#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    bool isPathCrossing(string path) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        unordered_set<string> st;
        
        int x = 0;
        int y = 0;
        string key = to_string(x) + "_" + to_string(y);
        st.insert(key);
        
        for(char &ch : path) {
            if(ch == 'E') {
                x += 1;
            } else if(ch == 'W') {
                x -= 1;
            } else if(ch == 'N') {
                y += 1;
            } else {
                y -= 1;
            }
            
            key = to_string(x) + "_" + to_string(y);
            if(st.find(key) != st.end()) {
                return true;
            }
            
            st.insert(key);
        }
        
        return false;
    }
};
