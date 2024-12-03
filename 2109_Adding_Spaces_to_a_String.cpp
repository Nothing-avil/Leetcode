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
    string addSpaces(string s, vector<int>& spaces) {
        // APPROACH 1

        string str = "";
        int n = spaces.size();
        int i =0, j= 0;
        for(int j = 0; j<s.size(); j++){
            if( i < n && spaces[i] == j){
                str += ' ';
                i++;
            }
            str += s[j];
        }
        return str;

        // Approach 2
        int total = s.size() + spaces.size();
        int n = spaces.size();
        char all[total];
        int i=0, h=0;
        for(int j = 0; j<s.size();){
            if(h < n && spaces[h] == j){
                all[i++] = ' ';
                h++;
            }
            all[i++] = s[j++];
        }
        return string(all, total);
    }
};
