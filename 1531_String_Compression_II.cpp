#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(int i, int k, string &s) {
        if(k < 0) {
            return 100000;
        }

        if(i >= n || (n-i) <= k) {
            return 0;
        }

        if(t[i][k] != -1) {
            return t[i][k];
        }

        int delete_i = solve(i+1, k-1, s);

        int keep_i = INT_MAX;
        
        int deleted  = 0;
        int freq     = 0;
        int addition = 0;

        for(int j = i; j < n && deleted <= k; j++) {
            if(s[j] == s[i]) {
                freq++;
                if(freq == 2 || freq == 10 || freq == 100) {
                    addition++;
                }
            } else {
                deleted++;
            }

            keep_i = min(keep_i, 1 + addition + solve(j+1, k-deleted, s));
        }

        return t[i][k] = min(delete_i, keep_i);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        n = s.length();
        t = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, s);
    }

};
