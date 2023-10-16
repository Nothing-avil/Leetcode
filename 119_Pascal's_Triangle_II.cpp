class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        for(int i=0; i<rowIndex+1; i++){
             
            vector<int>cont(i+1, 1);

            for(int j=1; j<i; j++){
                cont[j]= res[j]+res[j-1];
            }

            res=cont;
        }
        return res;
    }
};
