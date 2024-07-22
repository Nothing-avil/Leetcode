#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(falsae);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        for(int i=0; i<names.size(); i++){
            mp[heights[i]] = names[i];
        }
        vector<string> res;
        for(auto it: mp){
            res.push_back(it.second);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
