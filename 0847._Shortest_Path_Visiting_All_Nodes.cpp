class Solution {
public:
    typedef pair<int, int> p;

    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int c=0;

        if(n==1 || n==0){
            return 0;
        }
        queue<p> que;
        set<p> no;

        for(int i=0; i<n; i++){
            int mask= (1<<i);
            que.push({i, mask});
            no.insert({i, mask});
        }
        int all = pow(2, n)-1;
        int path=0;
        while(!que.empty()){
            int A= que.size();
            path++;
            
            while(A--){
                auto curr= que.front();
                que.pop();

                int node= curr.first;
                int currmas=curr.second;

                for(int &adj: graph[node]){
                    int nextmask= currmas | (1<<adj);
                    if(nextmask== all){
                        return path;
                    }
                    if(no.find({adj, nextmask})== no.end()){
                        no.insert({adj, nextmask});
                        que.push({adj, nextmask});
                    }
                }
            }
        }
        return -1;
    }
};
