class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int i=k;
        int j=k;
        int curr = nums[k];
        int res= nums[k];
        while(i>0 || j<n-1){
            int l = i>0?nums[i-1]:0;
            int r = j<n-1?nums[j+1]:0;
            if(l>r){
                i--;
                curr= min(curr, nums[i]);
            }
            else{
                j++;
                curr= min(curr, nums[j]);
            }
            res= max(res, curr*(j-i+1));
        }
        return res;
    }
};
