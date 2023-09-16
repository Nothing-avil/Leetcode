class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<pair<int, pair<int, int>>> q;
        q.push({0,{0, 0}});
        dist[0][0] = 0;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty())
        {
            int curr = -q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();

            if(x == n-1 && y == m-1) return curr;
            
            for(int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m)
                {
                    int diff = max(abs(heights[newX][newY] - heights[x][y]), curr);
                    if(dist[newX][newY] > diff)
                    {
                        dist[newX][newY] = diff;
                        q.push({-diff,{newX,newY}});
                    }
                }
            }


        }
        return 0;
    }
};
