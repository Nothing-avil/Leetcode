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
    long long wonderfulSubstrings(string word) {
        unordered_map<long long, long long> check;
        check[0]=1;
        int curr=0;
        long long res=0;
        for(char& i: word){
            int ch= i-'a';
            curr ^= (i<<ch);
            res+=check[curr];
            for(char i='a'; i<='j'; i++){
                ch= i-'a';
                long long error= curr^(i<<ch);
                res+= check[error];
            }
            check[curr]++;
        }
        return res;
    }
};
