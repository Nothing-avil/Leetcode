#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<int> res(26, 0);
        int x=0;
        for(char ch: tasks){
            res[ch-'A']++;
            x=max(x, res[ch-'A']);
        }
        int ans=0;
        for(int i=0; i<26; i++){
            ans+= res[i]==x;
        }
        return max((int) tasks.size(), ((x-1)*(n+1)+ans));
    }
};
