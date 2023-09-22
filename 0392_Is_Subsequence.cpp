class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n= t.length(), j=0, x=0;
        for(int i=0; i<n; i++){
            if(s[j]==t[i]){
                x++;
                j++;
            }
        }
        if(x==s.length()){
            return true;
        }
        return false;
        
    }
};
