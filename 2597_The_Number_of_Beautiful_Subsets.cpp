#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int mp[1010]{};
        int res=-1;
        function<void(int)> solver = [&](int i) {
            if(i>=nums.size()){
                res++;
                return;
            }
            solver(i+1);
            if((nums[i] - k < 0 || !mp[nums[i]-k]) && (nums[i] + k >= 1010 || !mp[nums[i]+k])){
                mp[nums[i]]++;
                solver(i+1);
                mp[nums[i]]--;
            }
        };
        solver(0);
        return res;
    }
};
