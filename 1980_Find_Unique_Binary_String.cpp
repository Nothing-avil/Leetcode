class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        string res;
        for(int i=0; i<nums.size(); i++){
            res+= (nums[i][i]=='1'? '0': '1');
        }
        return res;
    }
};
