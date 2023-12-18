#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        int firstMax  = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin  = INT_MAX;
        int secondMin = INT_MAX;
        for(int i = 0; i<n; i++) {
            
            if(nums[i] > firstMax) {
                secondMax = firstMax;
                firstMax = nums[i];
            } else {
                secondMax = max(secondMax, nums[i]);
            }
            if(nums[i] < firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            } else {
                secondMin = min(secondMin, nums[i]);
            }
        }
        return ((firstMax*secondMax)-(firstMin*secondMin));
    }
};
