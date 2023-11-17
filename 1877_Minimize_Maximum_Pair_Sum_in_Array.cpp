class Solution {
public:
    int minPairSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(begin(nums), end(nums));
        int i=0;
        int j= nums.size()-1, res=0;
        while(i<j){
            int ch= nums[j]+nums[i];
            res= max(res, ch);
            i++;
            j--;
        }
        return res;
    }
};
