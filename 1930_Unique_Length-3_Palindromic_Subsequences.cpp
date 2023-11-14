class Solution {
public:
    int countPalindromicSubsequence(string s) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=s.length();
        vector<pair<int, int>> ans(26, {-1, -1});
        for(int i=0; i<n; i++){
            char ch= s[i];
            int idk= ch-'a';
            if(ans[idk].first==-1){
                ans[idk].first=i;
            }
            ans[idk].second=i;
        }
        int res=0;
        for(int i=0; i<26; i++){
            int l=ans[i].first;
            int r=ans[i].second;
            if(ans[i]==make_pair(-1,-1)){
                continue;
            }
            unordered_set<char>str;
            for(int m = l+1; m <= r-1; m++) {
                
                str.insert(s[m]);
                
            }
            
            res += str.size();
        }
        return res;
    }
};
