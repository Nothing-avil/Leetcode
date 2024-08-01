// ██╗  ██╗███████╗██╗     ██╗      ██████╗
// ██║  ██║██╔════╝██║     ██║     ██╔═══██╗
// ███████║█████╗  ██║     ██║     ██║   ██║
// ██╔══██║██╔══╝  ██║     ██║     ██║   ██║
// ██║  ██║███████╗███████╗███████╗╚██████╔╝▄█╗
// ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ ╚═════╝ ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

//Approach 1
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int se =0;
        for(string ch: details){
            string c ="";
            c+= ch[11];
            c+=ch[12];
            if(c > "60"){
                se++;
            }
        }
        return se;
    }
};


//Approach 2
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int se =0;
        for(string ch: details){
            int age = ((ch[11]-'0')*10 + (ch[12]-'0'));
            se+=(age>60);
        }
        return se;
    }
};
