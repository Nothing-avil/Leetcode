// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int minLength(string s) {
        int i = 0, j = 1;
        int n=s.size();
        while(j<n){
            if(i >= 0 && ((s[i] == 'A' && s[j] == 'B') || (s[i]=='C' && s[j] == 'D'))){
                i--;
                j++;
            }
            else{
                i++;
                s[i] = s[j];
                j++;
            }
        }
        return i+1;

        stack<char> st;
        for(char i : s){
            if(st.empty()){
                st.push(i);
                continue;
            }
            char ch = st.top();
            if((ch == 'A' && i == 'B') || (ch=='C' && i == 'D')){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        return st.size();
    }
};
