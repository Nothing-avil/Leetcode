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
    double averageWaitingTime(vector<vector<int>>& customers) {
        int total = customers[0][0];
        double wait = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            if (total >= customers[i][0]) {
                total += customers[i][1];
                wait += (total - customers[i][0]);
            } else {
                total = customers[i][1] + customers[i][0];
                wait += (total - customers[i][0]);
            }
        }
        return (wait / (double)n);
    }
};
