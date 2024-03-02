#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> sorted(n);
        for (int i=n-1; i>=0; i--) {
            if (abs(nums[left]) >= abs(nums[right])) {
                sorted[i] = pow(nums[left], 2);
                left++;
            }
            else {
                sorted[i] = pow(nums[right], 2);
                right--;
            }
        }
        return sorted;
    }
};
