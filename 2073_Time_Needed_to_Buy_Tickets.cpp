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
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int c=0;
        for(int i=0; i<tickets.size(); i++){
            if(i<=k){
                c+= min(tickets[i], tickets[k]);
            }
            else{
                c+= min(tickets[i], tickets[k]-1);
            }
        }
        return c;
    }
};
