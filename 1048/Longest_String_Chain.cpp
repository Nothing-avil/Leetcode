class Solution {
public:
    int n;
    static bool solve(string& a1, string& a2){
        return a1.length() < a2.length();
    }
    bool isSubsequence(string s, string t) {
        int n= s.length();
        int m= t.length();
        if(n>=m || m-n!=1){
            return false;
        }
        int i=0;
        int j=0; 
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==n;
    }
    int longestStrChain(vector<string>& words) {
        n= words.size();
        sort(begin(words), end(words), solve);
        vector<int>t(n, 1);
        int maxs= 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isSubsequence(words[j], words[i])){
                    t[i]= max(t[i], t[j]+1);
                    maxs=max(maxs, t[i]);
                }
            }
        }
        return maxs;
    }
};
