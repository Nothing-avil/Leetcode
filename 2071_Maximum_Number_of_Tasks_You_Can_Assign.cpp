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
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size(), m = workers.size();
        int s = 0, e = min(n, m);
        function<bool(int)> check = [&](int i){
            int copy_p = pills;
            deque<int> dq;
            int k = 0;
            for(int j = m - i; j< m; j++){
                while(k < i && tasks[k] <= workers[j] + strength){
                    dq.push_back(tasks[k++]);
                }
                if(dq.empty()){
                    return false;
                }
                if(dq.front() <= workers[j]){
                    dq.pop_front();
                } else if(copy_p == 0){
                    return false;
                }else{
                    copy_p--;
                    dq.pop_back();
                }
            }
            return true;
        };
        while(s < e){
            int m = (s + e + 1)>>1;
            if(check(m)){
                s = m;
            }
            else{
                e = m - 1;
            }
        }
        return s;
    }
};
