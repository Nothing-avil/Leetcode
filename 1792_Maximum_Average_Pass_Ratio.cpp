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
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;
        int n = classes.size();
        for(int i=0; i<n; i++){
            double av = ((double) (classes[i][0]+1) / (double)( classes[i][1]+1)) - ((double) classes[i][0] / (double) classes[i][1]);
            pq.push({av, i});
        }
        while(extraStudents--){
            double av = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            classes[i][0]++;
            classes[i][1]++;
            av = ((double) (classes[i][0]+1) / (double)( classes[i][1]+1)) - ((double) classes[i][0] / (double) classes[i][1]);
            pq.push({av, i});
        }
        double avers= 0;
        while(!pq.empty()){
            int i = pq.top().second;
            pq.pop();
            avers += (((double) classes[i][0] / (double) classes[i][1]));
        }
        
        return avers/n;
    }
};
