#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<int> res;
        for(int i=1; i<9; i++){
            int check= i;
            for(int j=i+1; j<10; j++){
                check = check * 10 + j;
                if(check>=low && check<=high){
                    res.push_back(check);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
