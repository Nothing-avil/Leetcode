#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    long MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<int> dp(target + 1);
        for(int i = 1; i <= target && i <= k; ++i){
            dp[i] = 1;
        }
        int cur_max = min(2 * k, target);
        for(int d = 2; d <= n; ++d){
            int slide = 0;
            int left_bound = d - 1;
            int left = cur_max - k, right = cur_max - 1;
            //(left, right]
            for(int i = right; i > left && i >= left_bound; --i){
                slide = (slide + dp[i]) % MOD;
            }
            for(int i = cur_max; i >= d; --i, --left, --right){
                //[left, right]
                if(left >= left_bound){
                    slide = (slide + dp[left]) % MOD;
                }
                dp[i] = slide;
                //[left, right)
                slide = ((slide - dp[right]) % MOD + MOD) % MOD;
            }
            cur_max = min(cur_max + k, target);
        }
        return dp[target];
    }
};
