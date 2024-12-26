// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(int i : nums){
            s += i;
        }
        if((s+target)%2!=0) return 0;
        if(abs(target)>abs(s)) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2*s+1, -1));
        function<int(int, int)> solver = [&](int i, int sum){
            if(i == nums.size()){
                if(sum == target){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            if(dp[i][sum + s] != -1){
                return dp[i][sum+s];
            }
            int take = solver(i+1, sum+nums[i]);
            int nottake = solver(i+1, sum-nums[i]);
            return dp[i][sum+s] = (take + nottake);
        };
        return solver(0, 0);
    }
};
