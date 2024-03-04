#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        sort(tokens.begin(), tokens.end());
        int i=0; int j= tokens.size()-1;
        int ans=0, x=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-= tokens[i++];
                ans= max(ans, ++x);
            }
            else if(x){
                power+=tokens[j--];
                x--;
            }
            else{
                break;
            }
        }
        return ans;
    }

};
