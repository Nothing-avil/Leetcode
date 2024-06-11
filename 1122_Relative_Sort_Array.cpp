#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        unordered_map<int, int> mp;
        for (int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
        }
        for (int a : arr1) {
            if (!mp.count(a)) {
                mp[a] = INT_MAX;
            }
        }
        sort(arr1.begin(), arr1.end(), [&](auto a, auto b) {
            if (mp[a] == mp[b]) {
                return a < b;
            }
            return mp[a] < mp[b];
        });
        return arr1;
    }
};
