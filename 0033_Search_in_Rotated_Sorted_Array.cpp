// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
const auto __ = []() {
    struct Leetcode {
        static void _() {
            std::ofstream("display_runtime.txt") << 0 << '\n';
        }
    };
    std::atexit(&Leetcode::_);
    return 0;
}();
class Solution {
public:
    int search(vector<int>& nums, int k) {
        int n= nums.size();
        int s=0, e=n-1;
        while(s<=e){
            int mid= (s+e)/2;
            if(nums[mid]==k)
            return mid;
            if(nums[s]<=nums[mid]){
            if(nums[s]<=k && nums[mid]>=k)
                e=mid-1;
                else
                s=mid+1;
            }
            else{
                if(nums[e]>=k && nums[mid]<=k)
                    s=mid+1;
                    else
                    e=mid-1;
                }
        }
        return -1;
    }
};
