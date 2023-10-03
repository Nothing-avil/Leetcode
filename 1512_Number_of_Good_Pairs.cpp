class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> dp;
        int sum=0;
        for(int c: nums){
            sum+= dp[c];
            dp[c]++;
        }
        return sum;
    }
};
