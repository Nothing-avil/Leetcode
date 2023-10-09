class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int mid=0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid]==target){
                break;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(l>r){
            return {-1,-1};
        }
        int i=mid;
        while(i>=0 && nums[i]==target)i--;
        while(mid < nums.size() && nums[mid]==target)mid++;
        return {i+1,mid-1};
    }
};
