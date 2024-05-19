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
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int op = 0;
        long long ans = 0;
        vector<long long> pen;
        for(int x : nums){
            if((x ^ k) > x) {op++; ans += (x ^ k); pen.push_back((x ^ k) - x);}
            else {ans += x; pen.push_back(x - (x ^ k));}
        }
        sort(pen.begin(), pen.end());
        if(op % 2 == 0) return ans;
        return ans - pen[0];
    }
};
