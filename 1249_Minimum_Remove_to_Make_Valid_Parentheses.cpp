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
    string minRemoveToMakeValid(string s) {
        string t="";
        int ope=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                t.push_back(s[i]);
            }
            else if(s[i]=='('){
                ope++;
                t.push_back(s[i]);
            }
            else if(s[i]==')'){
                if(ope>0){
                    ope--;
                    t.push_back(s[i]);
                }
            }
        }
        string result="";
        for(int i=t.size()-1; i>=0; i--){
            if(t[i]>='a' && t[i]<='z'){
                result.push_back(t[i]);
            }
            else if(t[i]=='(' && ope>0){
                ope--;
            }
            else{
                result.push_back(t[i]);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
