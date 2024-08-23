// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
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
    string fractionAddition(string expression) {
        int up=0;
        int down=1;
        int n=expression.size();
        int i=0;
        while(i<n){
            int cup=0;
            int cdown=0;
            bool minus = (expression[i]=='-');
            if(expression[i]=='+' || expression[i]=='-'){
                i++;
            }
            while(i<n && isdigit(expression[i])){
                cup = cup*10+(expression[i]-'0');
                i++;
            }
            if(minus){
                cup*= -1;
            }
            i++;
            while(i<n && isdigit(expression[i])){
                cdown = cdown*10+(expression[i]-'0');
                i++;
            }
            up = up*cdown + cup*down;
            down= down*cdown;
        }
        int diff= abs(__gcd(up, down));
        up/=diff;
        down/=diff;
        return (to_string(up)+"/"+to_string(down));
    }
};
