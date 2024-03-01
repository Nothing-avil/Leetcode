#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int one=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                one++;
            }
        }
        one--;
        string str="";
        str.append(one, '1');
        str.append(n-one-1, '0');
        str += '1';
        return str;
    }
};
