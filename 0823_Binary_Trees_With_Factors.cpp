class Solution {
public:
    int mod= 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n= arr.size();
        unordered_map<int, long long> mp;
        mp[arr[0]]=1;
        for(int i=1; i<n; i++){
            int r= arr[i];
            mp[r]=1;
            for(int j=0; j<i; j++){
                int l= arr[j];
                if(r%l==0 && mp.find(arr[i]/l)!=mp.end()){
                    mp[r] += mp[l]*mp[arr[i]/l];
                }
            }
        }
        long res=0;
        for(auto &it: mp){
            res= (res + it.second)%mod;
        }
        return res;
    }
};
