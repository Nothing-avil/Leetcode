class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i=n-1;
        int j=m-1;

        int st=0;
        int ss=0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]== '#'){
                    ss++;
                    i--;
                }
                else if(ss>0){
                    ss--;
                    i--;
                }
                else{
                    break;
                }
            }
            while(j>=0){
                if(t[j]== '#'){
                    st++;
                    j--;
                }
                else if(st>0){
                    st--;
                    j--;
                }
                else{
                    break;
                }
            }
            char f = i < 0 ? '$' : s[i];
            char se = j < 0 ? '$' : t[j];
            if(se!=f){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};
