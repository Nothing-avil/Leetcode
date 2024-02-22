#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<int> arr(n+1);
        for(int i=0; i<trust.size(); i++){
            arr[trust[i][0]]--;
            arr[trust[i][1]]++;
        }
        for(int i=1; i<=n; i++){
            if(arr[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};
