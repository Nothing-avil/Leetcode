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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n= deck.size();
        vector<int> res(n);
        queue<int> qp;
        for(int i=0;i<n;i++){
            qp.push(i);
        }        
        for(int i=0; i<n;i++){
            int it= qp.front();
            qp.pop();
            qp.push(qp.front());
            qp.pop();
            res[it]= deck[i];
        }
        return res;
    }
};
