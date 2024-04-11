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
    string removeKdigits(string num, int k) {
        string str="";
        for(int i=0; i<num.size(); i++){
            while(k && str.size()>0 && str.back()>num[i]){
                k--;
                str.pop_back();
            }
            if(num[i]!='0' || str.size()>0){
                str.push_back(num[i]);
            }
        }
        while(k>0 && str.size()>0){
            str.pop_back();
            k--;
        }
        return str==""?"0":str;;
    }
};
