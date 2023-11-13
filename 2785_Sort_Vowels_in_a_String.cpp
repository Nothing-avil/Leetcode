class Solution {
public:
    bool isvowel(char s){
        s=tolower(s);
        return (s=='a'|| s=='e'||s=='i'||s=='o'||s=='u');
    }
    string sortVowels(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= s.size(), j=0;
        unordered_map<char, int> mp;
        for(char &c:s){
            if(isvowel(c)){
                mp[c]++;
            }
        }
        string c="AEIOUaeiou";
        for(int i=0; i<n; i++){
            if(isvowel(s[i])){
                while(mp[c[j]]==0){
                    j++;
                }
                s[i]=c[j];
                mp[c[j]]--;
            }
        }
        return s;
    }
};
