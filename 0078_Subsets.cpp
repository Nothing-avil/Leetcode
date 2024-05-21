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
    vector<vector<int>> res;
    void solver(vector<int>& nums, int i, vector<int>& ans){
        if(i==nums.size()){
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        solver(nums, i+1, ans);
        ans.pop_back();
        solver(nums, i+1, ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        solver(nums, 0, ans);
        return res;
    }
};
