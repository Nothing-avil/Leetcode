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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0, s=0;
        int dup=0;
        unordered_map<int, int> mp;
        for(int i=0; i<k; i++){
            s+= nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==2){
                dup++;
            }
        }
        sum = dup ? 0: s;
        for(int i=0; i<nums.size()-k; i++){
            s-=nums[i];
            mp[nums[i]]--;
            if(mp[nums[i]]==1){
                --dup;
            }
            s+= nums[i+k];
            mp[nums[i+k]]++;
            if(mp[nums[i+k]]==2){
                dup++;
            }
            if(!dup){
                sum = max(sum, s);
            }
        }
        return sum;
    }
};
