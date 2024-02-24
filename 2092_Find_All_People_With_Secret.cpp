#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    const static int N = 1e5+5;
    vector<pair<int,int>> vec1[N];
    vector<int> graph[N];
    bool vis[N];
    vector<int> temp;
    void dfs(int u){
        vis[u] = true;
        temp.push_back(u);
        for(auto v:graph[u]){
            if(!vis[v])
                dfs(v);
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& arr, int kk) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        for(int i=0;i<N;++i) {
            vec1[i].clear();
            vis[i] = false;
            graph[i].clear();
        }
        for(int i=0;i<arr.size();++i){
            int xi = arr[i][0];
            int yi = arr[i][1];
            int tt = arr[i][2];
            vec1[tt].push_back({xi,yi});
        }
        set<int> Set;
        Set.insert(0);
        Set.insert(kk);
        for(int i=0;i<N;++i){
            int sz = vec1[i].size();
            if(sz==0)
                continue;
            vector<int> arr2;
            for(int j=0;j<sz;j++) {
                int u = vec1[i][j].first;
                int v = vec1[i][j].second;
                graph[u].push_back(v);
                graph[v].push_back(u);
                arr2.push_back(u);
                arr2.push_back(v);
            }
            for(auto x:arr2){
                if(!vis[x]){
                    temp.clear();
                    dfs(x);
                    bool check = false;
                    for(auto y:temp){
                        if(Set.count(y)){
                            check = true;
                            break;
                        }
                    }
                    if(check){
                        for(auto y:temp){
                            Set.insert(y);
                        }
                    }
                }
            }
            for(auto x:arr2){
                vis[x] = false;
                graph[x].clear();
            }
        }
        vector<int> ans;
        for(auto x:Set)
            ans.push_back(x);
        return ans;
    }
};
