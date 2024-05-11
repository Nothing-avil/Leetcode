class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratio(n);

        for (int i = 0; i < n; ++i) {
            ratio[i] = {static_cast<double>(wage[i]) / quality[i], quality[i]};
        }

        sort(ratio.begin(), ratio.end());

        priority_queue<int> pq;
        int sumq = 0;
        double minCost = INT_MAX;

        for (auto& [r, q] : ratio) {
            pq.push(q);
            sumq += q;

            if (pq.size() > k) {
                sumq -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                minCost = min(minCost, r * sumq);
            }
        }

        return minCost;
    }
};
