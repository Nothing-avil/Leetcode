#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        unordered_map<int, int> mp;
        for(int& a: arr){
            mp[a]++;
        }
        vector<int> res;
        for(auto [_, c]: mp){
            res.push_back(c);
        }
        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++){
            k-=res[i];
            if(k<0){
                return res.size()-i;
            }
        }
        return 0;
    }
};
