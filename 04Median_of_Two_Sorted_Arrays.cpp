class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        v.insert(v.begin(), nums1.begin(), nums1.end());
        v.insert(v.end(), nums2.begin(), nums2.end());
        sort(v.begin(), v.end());
        int s= v.size();
        if(s%2!=0){
            return (double)v[s/2];
        }
        else{
            return (double)(v[(s/2)-1]+v[s/2])/2;
        }
    }
};
