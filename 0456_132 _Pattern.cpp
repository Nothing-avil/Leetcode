class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n= nums.size(), mins=INT_MIN;
        int j=n;
        if(nums.size()<3){
            return false;
        }
        for(int i=n-1; i>-1; i--){
            if(nums[i]<mins){
                return true;
            }
            while(j < n && nums[j]<nums[i]){
                mins=nums[j];
                j++;
            }

            j--;
            nums[j]=nums[i];
        }
        return false;
    }
};
