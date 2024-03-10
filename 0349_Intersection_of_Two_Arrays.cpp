#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for(int a: nums2){
            if(st.find(a)!=st.end()){
                res.insert(a);
            }
        }
        return vector<int> (res.begin(), res.end());
    }
};
