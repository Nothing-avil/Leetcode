class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1=0;
        int maj1=0;

        int count2=0;
        int maj2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==maj1){
                count1++;
            }
            else if(nums[i]==maj2){
                count2++;
            }
            else if(count1==0){
                maj1=nums[i];
                count1=1;
            }
            else if(count2==0){
                maj2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> res;
        int f=0;
        int r=0;
        for(int &ans:nums){
            if(ans==maj1){
                f++;
            }
            else if(ans==maj2){
                r++;
            }
        }
        if(f>floor(n/3)){
            res.push_back(maj1);
        }
        if(r>floor(n/3)){
            res.push_back(maj2);
        }
        return res;
    }
};
