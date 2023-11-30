#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int minimumOneBitOperations(int n) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        if(n==0){
            return 0;
        }
        vector<long long>f(31, 0);
        f[0]=1;
        for(int i=1; i<31; i++){
            f[i]= 2*f[i-1]+1;
        }
        int s=1;
        int res=0;
        for(int i=30; i>=0; i--){
            int c = ((1<<i)&n);
            if(c==0){
                continue;
            }

            if(s>0){
                res+= f[i];
            }
            else{
                res-= f[i];
            }
            s=s*(-1);
        }
        return res;
    }
};
