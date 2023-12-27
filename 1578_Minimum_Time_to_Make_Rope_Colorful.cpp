#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= colors.size();
        int ti=0;
        int prevMax=0;
        for(int i = 0; i<n; i++) {
            if(i > 0 && colors[i] != colors[i-1]) {
                prevMax = 0;
            }
            int curr = neededTime[i];
            ti += min(prevMax, curr);
            prevMax = max(prevMax, curr);
        }
        return ti;
    }
};
