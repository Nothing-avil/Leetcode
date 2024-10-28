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
    int longestSquareStreak(vector<int>& nums) {

        //Approch 1

        unordered_map<int, int> mp;
        for(int i : nums){
            int x = sqrt(i);
            if( x*x == i){
                mp[x] = i;
            }
        }
        int c=0;
        for(int i : nums){
            int m = 0;
            int s = i;
            while(s){ 
                m++;
                s = mp[s];
                if(s==0){
                    break;
                }
            }
            c = max(m, c);
        }
        return c<=1 ? -1 : c;

        //Approach 2

        vector<int> res(100001, false);
        for(int i: nums){
            res[i] = true;
        }
        int ans = -1;
        for(size_t i= 0; i<100000; i++){
            if(!res[i]){
                continue;
            }
            int l = 0;
            size_t ind = i;
            while(ind<100000 && res[ind]){
                l++;
                ind = ind*ind;
            }
            if(l>1){
                ans = max(ans, l);
            }
        }
        return ans;
    }
};
