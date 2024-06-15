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
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n =profits.size();
        vector<pair<int,int>> res(n);
        for(int i=0; i<n; i++){
            res[i]={capital[i], profits[i]};
        }
        sort(begin(res), end(res));
        priority_queue<int> qu;
        int i=0;
        while(k--){
            while(i < n && res[i].first <= w){
                qu.push(res[i].second);
                i++;
            }

            if(qu.empty()){
                break;
            }
            w += qu.top();
            qu.pop();
        }
        return w;
    }
};
