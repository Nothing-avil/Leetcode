#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int mod= 1e9+7;
    int numberOfWays(string corridor) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=corridor.size();
        vector<int>arr;
        for(int i=0; i<n; i++){
            if(corridor[i]=='S'){
                arr.push_back(i);
            }
        }
        if(arr.size()%2!=0 || arr.size()==0){
            return 0;
        }
        long long res=1;
        int p =arr[1];
        for(int i=2; i<arr.size(); i+=2){
            int l= arr[i]-p;
            res= (res*l)%mod;
            p= arr[i+1];
        }
        return res;
    }
};
