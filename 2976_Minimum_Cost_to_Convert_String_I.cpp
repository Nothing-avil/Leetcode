// ██╗  ██╗███████╗██╗     ██╗      ██████╗
// ██║  ██║██╔════╝██║     ██║     ██╔═══██╗
// ███████║█████╗  ██║     ██║     ██║   ██║
// ██╔══██║██╔══╝  ██║     ██║     ██║   ██║
// ██║  ██║███████╗███████╗███████╗╚██████╔╝▄█╗
// ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ ╚═════╝ ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26, vector<long long>(26, INT_MAX));
        for(int i=0; i < original.size(); i++){
            adj[original[i]-'a'][changed[i]-'a'] = min(adj[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);
            
        }
        long long res=0;
        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    // if (adj[i][j] > (adj[i][k] + adj[k][j]) && (adj[k][j] != LLONG_MAX && adj[i][k] != LLONG_MAX)){
                        adj[i][j] = min(adj[i][j], (adj[k][j]+adj[i][k]));
                    // }
                }
            }
        }
        for(int i=0; i<source.size(); i++){
            if(source[i]==target[i]){
                continue;
            }
            if(adj[source[i]-'a'][target[i]-'a'] == INT_MAX){
                return -1;
            }
            res+= adj[source[i]-'a'][target[i]-'a'];
        }
        return res;
    }
};
