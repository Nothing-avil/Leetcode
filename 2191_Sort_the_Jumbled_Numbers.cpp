#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> res;

        auto getter = [&](string s){
            string str="";
            for(char ch: s){
                str+= to_string(mapping[ch-'0']);
            }
            return str;
        };
        vector<int> sandy;
        for(int i=0; i<nums.size(); i++){
            string str= to_string(nums[i]);
            string newstr = getter(str);
            int val = stoi(newstr);
            res.push_back({val, i});
        }
        sort(res.begin(), res.end());
        for(auto i: res){
            sandy.push_back(nums[i.second]);
        }
        return sandy;
    }
};
