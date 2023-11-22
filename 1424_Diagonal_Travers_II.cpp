  class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        queue<pair<int, int>> que;
        que.push({0,0});
        vector<int> res;
        while(!que.empty()){
            auto [i, j]= que.front();
            que.pop();
            res.push_back(nums[i][j]);
            if(j==0 && i+1<nums.size()){
                que.push({i+1,j});
            }
            if(j+1<nums[i].size()){
                que.push({i,j+1});
            }
        }
        return res;
    }
};
