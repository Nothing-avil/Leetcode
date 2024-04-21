#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:

    bool answer(unordered_map<int, vector<int>>& graph, int source, int destination, vector<bool> & vis){
        if(source==destination){
            return true;
        }
        if(vis[source]==true){
            return false;
        }
        vis[source]= true;
        for(auto &it: graph[source]){
            if(answer(graph, it, destination, vis)==true){
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(vector<int> &g: edges){
            int u= g[0], v= g[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n, false);
        
        return answer(graph, source, destination, vis);
    }
};
