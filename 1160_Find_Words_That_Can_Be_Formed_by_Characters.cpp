#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<int> vec(26, 0);
        for(char &ch: chars){
            vec[ch-'a']++;
        }
        int res=0;
        for(string &st: words){
            vector<int>wo(26, 0);
            for(char &ar: st){
                wo[ar-'a']++;
            }
            bool t=true;
            for(int i=0; i<26; i++){
                if(wo[i]>vec[i]){
                    t=false;
                }
            }
            if(t==true){
                res += st.size();
            }
        }
        return res;
    }
};
