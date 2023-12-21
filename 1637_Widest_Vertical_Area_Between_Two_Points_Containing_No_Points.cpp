#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(points.begin(), points.end());
        int maxs=0;
        for(int i=1; i<points.size(); i++){
            maxs= max(maxs, points[i][0]-points[i-1][0]);
        }
        return maxs;
    }
};
