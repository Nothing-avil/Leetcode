class Solution {
public:
    char findTheDifference(string s, string t) {
        int a=0;
        for(char r: s){
            a^=r;
        }
        for(char r: t){
            a^= r;
        }
        return (char)a;
    }
};
