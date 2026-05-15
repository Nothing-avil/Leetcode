#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= nums.size();
        if (nums[0] <= nums[n - 1]) return nums[0];
        int l=0, r=n-1;
        while(l<r){
            int mid= (l + r) >> 1;
            if (nums[0] <= nums[mid])
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};
