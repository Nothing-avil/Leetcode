class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        vector<int> c(26);
        unordered_set<int> used;

        for(auto f: s){
            c[f-'a']++;
        }

        for(auto a: c){
            while(a>0 && !used.insert(a).second){
                a--;
                ans++;
            }
        }

        return ans;
    }
};
