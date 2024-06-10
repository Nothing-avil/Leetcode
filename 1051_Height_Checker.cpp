#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int c[101]={0};
        for(int h: heights){
            c[h]++;
        }
        int x=0, j=0;
        for(int i=0;i<101;){
            if(c[i]==0){
                i++;
                continue;
            }
            if(i!=heights[j]){
                x++;
            }
            j++;
            c[i]--;
        }
        return x;
    }
};
