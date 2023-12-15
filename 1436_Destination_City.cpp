#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        ios_base::sync_with_stdio(0), cin.tie(0),  cout.tie(0);
        unordered_set<string> st;
        for(auto &pt: paths){
            string s= pt[0];
            st.insert(s);
        }
        for(auto &f: paths){
            string d = f[1];
            if(st.find(d)==st.end()){
                return d;
            }
        }
        return "";
    }
};
