class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        unordered_map<int, int>mp;
        int n=arr.size();
        int x= (n/4);
        for(int el: arr){
            mp[el]++;
            if(mp[el]>x){
                return el;
            }
        }
        return -1;
    }
};
