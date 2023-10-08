class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<int>dp1(nums2.size()+1,INT_MIN);
        vector<int>dp2(nums2.size()+1,INT_MIN);
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
                dp1[j]=max({nums1[i-1]*nums2[j-1],dp2[j],dp1[j-1],nums1[i-1]*nums2[j-1]+max({0,dp2[j-1]})});
            }
            swap(dp1,dp2);
        }
        return dp2[nums2.size()];
    }
};
