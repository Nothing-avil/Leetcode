#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        // sort(nums.begin(), nums.end());
        sort(nums.begin(), nums.end(), [&](int & a, int & b){
            if(mp[a] == mp[b]){
                return a>b;
            }
            return mp[a]<mp[b];
        });
        return nums;
    }
};
