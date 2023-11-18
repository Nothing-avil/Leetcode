class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(begin(nums), end(nums));
        int n= nums.size();
        int res=0;
        int l=0;
        long curr=0;
        for(int j=0;j<n; j++){
            long tar= nums[j];
            curr+= nums[j];
            if((j-l+1)*tar- curr>k){
                curr-= nums[l];
                l++;
            }
            res= max(res, j-l+1);
        }
        return res;
    }
};
