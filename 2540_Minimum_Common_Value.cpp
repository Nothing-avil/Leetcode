#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=nums1.size();
        int m= nums2.size();
        int i=0, j=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }
            if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return -1;
    }
};
