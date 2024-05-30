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
    int countTriplets(vector<int>& arr) {
        int dump=0;
        int n= arr.size();
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=1;i<=n;i++){
            prefix[i]= prefix[i-1]^arr[i-1];
        }
        int dumd=0;
        for(int i=0; i<=n; i++){
            for(int k=i+1; k<=n; k++){
                if(prefix[i]==prefix[k]){
                    dumd+=(k-i-1);
                }
            }
        }
        return dumd;
    }
};
