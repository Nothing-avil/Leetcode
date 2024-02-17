#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int c=0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<heights.size()-1; i++){
            int d= heights[i+1]- heights[i];
            if(d>0){
                q.push(d);
                if(q.size()>ladders){
                    bricks-=q.top();
                    q.pop();
                    if(bricks<0){
                        return i;
                    }
                }
            }
        }
        return heights.size()-1;
    }
};
