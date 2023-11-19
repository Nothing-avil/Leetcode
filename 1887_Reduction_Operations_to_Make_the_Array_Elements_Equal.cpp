class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(begin(nums), end(nums));
        int res=0;
        int n= nums.size();
        for(int i=n-1; i>0; i--){
            if(nums[i]!=nums[i-1]){
                res= res+(n-i);
            }
        }
        return res;
    } 
};     
