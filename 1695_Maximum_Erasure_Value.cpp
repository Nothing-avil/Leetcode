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
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> pos(10001, -1);
        int i=0, j=0, sum = 0, answer = INT_MIN, n = nums.size();
        while(i < n){
            if(pos[nums[i]] != -1){
                while(j <= pos[nums[i]]){
                    sum -= nums[j];
                    j++;
                }
            }
            sum += nums[i];
            answer = max(answer, sum);
            pos[nums[i]] = i;
            i++;
        }
        return answer;

        // int i = 0, j= 0, n = nums.size();
        // int answer = INT_MIN;
        // int sum = 0;
        // unordered_map<int, int> mp;
        // while(i < n){
        //     sum += nums[i];
        //     mp[nums[i]]++;
        //     while(mp.size() != i - j + 1){
        //         sum -= nums[j];
        //         if(--mp[nums[j]] == 0){
        //             mp.erase(nums[j]);
        //         }
        //         j++;
        //     }
        //     i++;
        //     answer = max(answer, sum);
        // }
        // return answer;
    }
};
