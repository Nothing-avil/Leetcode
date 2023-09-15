class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> dist(points.size(), INT_MAX);
        int ans = 0;

        for (int i = 0; i < points.size() - 1; ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                dist[j] = min(dist[j], abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                if (dist[j] < dist[i + 1]) {
                swap(points[j], points[i + 1]);
                swap(dist[j], dist[i + 1]);
                }
            }
            ans += dist[i + 1];
        }    
        return ans;
    }
};
