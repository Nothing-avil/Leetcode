// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> inner;
        unordered_map<int, int> outter;
        for(auto& p : pairs){
            adj[p[0]].push_back(p[1]);
            inner[p[1]]++;
            outter[p[0]]++;
        }
        int start = pairs[0][0];
        for(auto& i : adj){
            if(outter[i.first] - inner[i.first]  == 1){
                start = i.first;
                break;
            }
        }
        vector<int> eluer;
        stack<int> st;
        st.push(start);
        while(!st.empty()) {
           int curr = st.top();
           if(!adj[curr].empty()) {
               int ngbr = adj[curr].back();
               adj[curr].pop_back();
               st.push(ngbr);
           } else {
               eluer.push_back(curr);
               st.pop();
           }
        }
        reverse(begin(eluer), end(eluer));
        vector<vector<int>> result;
        for(int i = 0; i < eluer.size()-1; i++) {
            result.push_back({eluer[i], eluer[i+1]});
        }

        return result;
    }
};
