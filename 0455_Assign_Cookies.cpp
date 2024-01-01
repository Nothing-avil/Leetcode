#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int findContentChildren(vector<int>& good, vector<int>& sol) {
        sort(begin(good), end(good));
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(begin(sol), end(sol));
        int m = good.size();
        int n = sol.size();
        
        int count = 0;
        int j = 0;
        
        while(count < m && j < n) {
            if(good[count] <= sol[j]) {
                count++;
            }
            j++;
        }
        
        return count;
    }
};
