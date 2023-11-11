class Graph {
public:
    vector<vector<pair<int, int>>> adj_list;
Graph(int n, vector<vector<int>>& edges) {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    adj_list.resize(n);
    for (auto& e: edges)
        adj_list[e[0]].push_back(make_pair(e[1], e[2]));
}

void addEdge(vector<int> e) {
    adj_list[e[0]].push_back(make_pair(e[1], e[2]));
}

int shortestPath(int node1, int node2) {
    int n = adj_list.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[node1] = 0;
    pq.push(make_pair(0, node1));
    
    while (!pq.empty()) {
        int d = pq.top().first, node = pq.top().second; pq.pop();
        if (node == node2) return d;
        if (d > dist[node]) continue;
        for (auto& neighbor : adj_list[node]) {
            int new_dist = d + neighbor.second;
            if (new_dist < dist[neighbor.first]) {
                dist[neighbor.first] = new_dist;
                pq.push(make_pair(new_dist, neighbor.first));
            }
        }
    }
    return -1;
}
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
