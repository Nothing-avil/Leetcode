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
    int lengthOfLastWord(string s) {
        int c=0;
        int n=s.size();
        while(s[n-1]==' '){
            n--;
        }
        for(int i=0;i<n;i++){
            c++;
            if(s[i]==' '){
                c=0;
            }
        }
        return c;
    }
};
