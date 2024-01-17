#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<int> vec(2001, 0);
        
        for(int &x : arr) {
            vec[x + 1000]++;
        }
        
        for(int i = 1; i<2001; i++) {
            if(vec[i] == 0) continue;

            int idx = abs(vec[i]);
            
            if (vec[idx] < 0) {
                return false;
            }

            vec[idx] = -1;
        }
        
        
        return true;
    }
};
