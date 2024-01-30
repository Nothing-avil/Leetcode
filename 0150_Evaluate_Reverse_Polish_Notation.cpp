#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        stack<int> st;
        for(auto s:tokens){
            if(s.size()>1 || isdigit(s[0])){
                st.push(stoi(s));
            } else {
                int y=st.top();
                st.pop();
                int x=st.top();
                st.pop();
                if(s[0]=='+'){
                    st.push((x+y));
                }
                else if(s[0]=='-'){
                    st.push((x-y));
                }
                else if(s[0]=='*'){
                    st.push((x*y));
                }
                else if(s[0]=='/'){
                    st.push((x/y));
                }
            }
        }
        return st.top();
    }
};
