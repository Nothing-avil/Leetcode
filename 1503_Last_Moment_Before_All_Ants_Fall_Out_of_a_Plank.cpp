class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res=0;
        for(int &u: right){
            res= max(res, n-u);
        }
        for(int &u: left){
            res= max(res, u);
        }
        return res;
    }
};
