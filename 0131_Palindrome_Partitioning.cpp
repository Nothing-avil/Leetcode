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

    bool check(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void solver(string& s, int id, vector<string>& c, vector<vector<string>>& res){
        if(id==s.size()){
            res.push_back(c);
            return;
        }
        for(int i=id; i<s.size(); i++){
            if(check(s, id, i)){
                c.push_back(s.substr(id, i-id+1));
                solver(s, i+1, c, res);
                c.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> c;
        solver(s, 0, c, res);
        return res;
    }
};
