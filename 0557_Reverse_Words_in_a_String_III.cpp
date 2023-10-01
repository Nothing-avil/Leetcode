class Solution {
public:
    string reverseWords(string s) {
        stringstream qwerty(s);

        string t = "";
        string res = "";

        while(qwerty >> t){
            reverse(begin(t), end(t));

            res += t + " ";
        }

        return res.substr(0, res.length()-1);
    }
};
