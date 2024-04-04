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
    int maxDepth(string s) {
        int c=0;
        int maxi=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                maxi++;
            }
            if(s[i]==')'){
                maxi--;
            }
            c=max(c, maxi);
        }
        return c;
    }
};
