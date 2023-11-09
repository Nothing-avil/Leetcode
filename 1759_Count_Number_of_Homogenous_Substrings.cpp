class Solution {
public:
    int mod=1e9+7;
    int countHomogenous(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
        int c=0;
        int k=0;
        for(int i=0; i<s.length(); i++){
            if(i>0 && s[i]==s[i-1]){
                c++;
            }
            else{
                c=1;
            }
            k= (k+c)%mod;
        }
        return k;
    }
};
