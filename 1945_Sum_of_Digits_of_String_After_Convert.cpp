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
    int getLucky(string s, int k) {
        // Approch 1
        string str= "";
        for(char ch : s){
            int i = ch-'a'+1;
            str = str + to_string(i);
        }
        int m=0;        
        while(k--){
            int c=0; 
            for(char ch: str){
                c+= (ch-'0');
            }
            str = to_string(c);
            m=c;
        }
        return m;

        //Approch 2
        int sum=0;
        for(char ch : s){
            int i = ch-'a'+1;
            if(i>=10){
                sum += (i/10 + i%10);
            }
            else{
                sum += i;
            }
        }
        k--;
        while(k-- && sum>=10){
            int t=0;
            while(sum>0){
                t += sum%10;
                sum=sum/10;
            }
            sum=t;
        }
        return sum;
    }
};
