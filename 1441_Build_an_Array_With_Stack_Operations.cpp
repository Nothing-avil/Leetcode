class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int i=1, j=0;
        while(i<=n && j<target.size()){
            res.push_back("Push");
            if(i==target[j]){
                j++;
            }
            else{
                res.push_back("Pop");
            }
            i++;
        }
        return res;
    }
};
