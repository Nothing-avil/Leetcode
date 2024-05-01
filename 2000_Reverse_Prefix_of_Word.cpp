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
    string reversePrefix(string word, char ch) {
        int i=0, j=0;
        int n= word.size();
        while(word[j]!= ch && j<n){
            j++;
        }
        if(j==n){
            return word;
        }
        while(i<j){
            swap(word[i++], word[j--]);
        }
        return word;
    }
};
