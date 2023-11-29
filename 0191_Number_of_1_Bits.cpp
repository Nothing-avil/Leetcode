class Solution {
public:
    int hammingWeight(uint32_t n) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int c=0;
        while(n){
            c++;
            n= (n&(n-1));
        }
        return c;
    }
};
