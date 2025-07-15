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
    bool isValid(string word) {
        auto isvowel = [](char c){
            string st = "aeiouAEIOU";
            return (st.find(c) != string::npos);
        };

        auto ischaracter = [](char c){
            string st = "qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM";
            return (st.find(c) != string::npos);
        };

        bool vol = false, conso = false;
        if(word.size() < 3){
            return false;
        }
        for(char ch : word){
            if(ch >='0' && ch <= '9'){
                continue;
            }
            if(isvowel(ch)){
                vol = true;
            }
            else if(ischaracter(ch)){
                conso = true;
            }
            else{
                return false;
            }
        }
        return (vol && conso);
    }
};
