class Solution {
public:
    bool checks(vector<int> &ans){
        unordered_set<int> st;
        int n = ans.size();
        int mine = INT_MAX;
        int maxe = INT_MIN;
        for (int &num : ans) {
            mine = min(mine, num);
            maxe = max(maxe, num);
            st.insert(num);
        }
        if((maxe-mine)%(n-1)!=0){
            return false;
        }
        int d= (maxe-mine)/(n-1);
        int ele= mine+d;
        while(ele<maxe){
            if(st.find(ele)==st.end()){
                return false;
            }
            ele = ele + d;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<bool> res;
        int n= l.size();
        for(int i=0; i<n; i++){
            vector<int>ans(begin(nums)+l[i], begin(nums)+r[i]+1);
            res.push_back(checks(ans));
        }
        return res;
    }
};
