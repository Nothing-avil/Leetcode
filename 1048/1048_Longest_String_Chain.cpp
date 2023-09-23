class Solution {
public:
    int t[1001][1001];
    int n;
    static bool solve(string& a1, string& a2){
        return a1.length() < a2.length();
    }
    bool isSubsequence(string s, string t) {
      //yha hm string matching karenge
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
    int gone(vector<string>& words, int pre, int curr){
      //ye sb return karega aur hm yha pe tree ka concept lagayene
      //fullly recursion
        if(curr==n){
            return 0;
        }
        int take=0, not_take=0;

        if(pre != -1 && t[pre][curr] != -1){
            return t[pre][curr];
        }

        if(pre == -1 || isSubsequence(words[pre], words[curr])){
            take = 1 + gone(words, curr, curr+1);
        }

        not_take = gone(words, pre, curr+1);

        if(pre != -1){
            t[pre][curr]=max(take, not_take);
        }

        return max(take, not_take);
    }
    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        n= words.size();
        sort(begin(words), end(words), solve);
        return gone(words, -1, 0);
    }
};
