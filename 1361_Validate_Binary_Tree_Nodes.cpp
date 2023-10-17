class Solution {
    int count(int no, vector<int>& l, vector<int>& r){
        if(no==-1)return 0;

        return 1+count(l[no], l,r) + count(r[no], l, r);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            if(l[i]!=-1 && res[l[i]]++==1)return false;
            if(r[i]!=-1 && res[r[i]]++==1)return false;
        }
        int ro=-1;
        for(int i= 0; i<n; i++){
            if(res[i]==0){
                if(ro!=-1)return false;
                ro=i;
            }
        }
        if(ro == -1){
            return false;
        }
        return count(ro, l, r)==n;
    }
};
