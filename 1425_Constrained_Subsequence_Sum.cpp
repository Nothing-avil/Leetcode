class Solution {
public:
    typedef pair<int, int> P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ress(n);
        for(int i=0; i<n; i++){
            ress[i]=nums[i];
        }
        priority_queue<P> pq;
        pq.push({ress[0], 0});
        int res = ress[0];
        for(int i=1; i<n; i++){
            while(!pq.empty() && i-pq.top().second > k){
                pq.pop();
            }
            ress[i]= max(ress[i], nums[i]+pq.top().first);
            pq.push({ress[i], i});
            res= max(res, ress[i]);
        }
        return res;
    }
};
