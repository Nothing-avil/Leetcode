class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n= arr.size(), s=0;
        int maxs = *max_element(begin(arr), end(arr));
        if(k>n){
            return maxs;
        }
        int w= arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]<w){
                s++;
            }
            else{
                w=arr[i];
                s=1;
            }
            if(s>=k){
                return w;
            }
        }
        return maxs;
    }
};
