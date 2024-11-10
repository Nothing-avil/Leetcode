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
    void solve(vector<int>& val, int n, int c){
        int i=0;
        while(n>0){
            int r=n%2;
            if(r==1){
                if(c&1){
                    val[i]+=1;
                }
                else{
                    val[i]-=1;
                }
            }
            n=n/2;
            i++;
        }
    }
    int call(vector<int>& val){
        int res=0;
        int ans=1;
        for(int i=0;i<30; i++){
            if(val[i]>=1){
                res+=ans;
            }
            ans= ans*2;
        }
        return res;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> val(32, 0);
        int i, j=0;
        int len=0;
        int res=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            len=len|nums[i];
            solve(val, nums[i], 1);
            while(i>=j && len>=k){
                res= min(res, i-j+1);
                solve(val, nums[j], 0);
                len= call(val);
                j++;
            }
        }
        return res==INT_MAX?-1:res;
    }
};
