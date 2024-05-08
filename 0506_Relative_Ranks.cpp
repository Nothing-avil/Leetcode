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
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> check(score.begin(), score.end());
        sort(check.begin(), check.end(), greater<int>());
        vector<string> res;
        for(int i=0; i<score.size(); i++){
            if(score[i]==check[0]){
                res.push_back("Gold Medal");
            }
            else if(score[i]==check[1]){
                res.push_back("Silver Medal");
            }
            else if(score[i]==check[2]){
                res.push_back("Bronze Medal");
            }
            else{
                res.push_back(to_string((find(check.begin(), check.end(), score[i]))- check.begin()+1));
            }
        }
        return res;
    }
};
