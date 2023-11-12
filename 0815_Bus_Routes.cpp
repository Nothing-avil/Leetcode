class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        if(source==target){
            return 0;
        }
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<routes.size(); i++){
            for(auto &rt: routes[i]){
                mp[rt].push_back(i);
            }
        }
        queue<int> Q;
        vector<bool> visit(501, false);
        for(auto &rt: mp[source]){
            Q.push(rt);
            visit[rt]= true;
        }
        int bus=1;
        while(!Q.empty()){
            int s= Q.size();
            while(s--){
                int rt= Q.front();
                Q.pop();

                for(auto &st: routes[rt]){
                    if(st==target){
                        return bus;
                    }
                    for(auto &nt: mp[st]){
                        if(visit[nt] == false){
                            visit[nt] = true;
                            Q.push(nt);
                        }
                    }
                }
            }
            bus++;
        }
        return -1;
    }
};
