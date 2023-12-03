#pragma GCC  optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= points.size();
        int s=0;
        for(int i=0; i<n-1; i++){
            int x1= points[i][0];
            int y1= points[i][1];
            int x2= points[i+1][0];
            int y2= points[i+1][1];
            int x= abs(x2-x1);
            int y= abs(y2-y1);
            s+= min(y,x)+ abs(y-x);
        }
        return s;
    }
};
