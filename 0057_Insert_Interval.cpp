#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<vector<int>> res;
        int i=0;
        int n= intervals.size();
        while(i<n){
            if(intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newInterval[1]){
                break;
            }
            else{
                newInterval[0]=min(newInterval[0], intervals[i][0]);
                newInterval[1]=max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        res.push_back(newInterval);
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
