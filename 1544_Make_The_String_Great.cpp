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
    string makeGood(string s) {
        stack<char> stk;
        for(int i=s.size()-1;i>=0; i--){
            if(stk.empty() || abs(stk.top()-s[i])!=32){
                stk.push(s[i]);
            }
            else{
                stk.pop();
            }
        }
        string str="";
        while(!stk.empty()){
            str.push_back(stk.top());
            stk.pop();
        }
        return str;
    }
};
