#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int totalMoney(int n) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int sum=0;
        int a, c=1;
        for(int i=1; i<=n; i++){
            if(i%7==1){
                a=c++;
            }
            sum+= a;
            a++;
        }
        return sum;
    }
};
