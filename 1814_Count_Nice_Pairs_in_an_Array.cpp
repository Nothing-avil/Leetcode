class Solution {
public:
    int mod= 1e9+7;
    int rev(int a){
        int n=0;
        while(a>0){
            int x=a%10;
            n=n*10+x;
            a=a/10;
        }
        return n;
    }
    int countNicePairs(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=nums.size();
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            nums[i]= nums[i]-rev(nums[i]);
        }
        int res=0;
        for(int i=0; i<n; i++){
            res=(res+mp[nums[i]])%mod;
            mp[nums[i]]++;
        }
        return res%mod;
    }
};
