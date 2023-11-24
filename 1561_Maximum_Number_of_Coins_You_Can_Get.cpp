#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int res=0;
        sort(begin(piles), end(piles));
        int n= piles.size();
        for(int i= n/3; i<n; i+=2){
            res= res+ piles[i];
        }
        return res;
    }
};
