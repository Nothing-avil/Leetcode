class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
        int h= max(abs(sx-fx), abs(sy-fy));
        if(h==0 && t==1){
            return false;
        }
        if(h>t){
            return false;
        }
        return true;
    }
};
