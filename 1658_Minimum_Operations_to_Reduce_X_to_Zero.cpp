class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //arr ka sum index ke sath store krne ke liye map
        unordered_map<int, int> ans;
        int s=nums.size(), sum=0;
        //not found condition
        ans[0]=-1;
        for(int i=0; i<s; i++){
            sum =sum+ nums[i];
            ans[sum]=i;
        }
        if(sum<x){
            return -1;
        }
        //finding longest remaining subarray
        int diff= sum-x;
        int finds= INT_MIN;
        sum=0;
        //finding min arr size
        for(int i=0; i<s; i++){
            sum=sum+nums[i];
            int rest= sum-diff;
            if(ans.find(rest)!=ans.end()){
                int res= ans[rest];
                finds=max(finds, i-res);
            }
        }
        return finds==INT_MIN ? -1: (s-finds);
    }
};
