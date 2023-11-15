class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= arr.size();
        sort(begin(arr), end(arr));
        int res=-1;
        for(int i=0; i<n; i++){
            if(i==0){
                arr[i]=1;
            }
            else if(abs(arr[i])-arr[i-1]>1){
                arr[i]=arr[i-1]+1;
            }
            res= max(res, arr[i]);
        }
        return res;
    }
};
