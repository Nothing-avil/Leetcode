#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=points.size();
        int c=1;
        sort(points.begin(), points.end());
        vector<int> prev= points[0];
        for(int i=1; i<n; i++){
            int curpoint= points[i][0];
            int endpoint= points[i][1];
            int pres= prev[0];
            int pree= prev[1];
            if(curpoint>pree){
                c++;
                prev= points[i];
            }
            else{
                prev[0]=max(pres, curpoint);
                prev[1]=min(pree, endpoint);
            }
        }
        return c;
    }
};
