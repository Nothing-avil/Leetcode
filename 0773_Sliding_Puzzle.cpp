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
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";
        unordered_map<int, vector<int>> mp = {
            {0, {1, 3}},
            {1, {0, 2, 4}},
            {2, {1, 5}},
            {3, {0, 4}},
            {4, {1, 3, 5}},
            {5, {2, 4}}
        };
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start += (board[i][j] + '0');
            }
        }
        queue<string> qu;
        qu.push(start);
        unordered_set<string> vist;
        vist.insert(start);
        int lev =0;
        while(!qu.empty()){
            int n = qu.size();
            while(n--){
                string s = qu.front();
                qu.pop();
                if(s == target){
                    return lev;
                }
                int i = s.find('0');
                for(int j : mp[i]){
                    string ss = s;
                    swap(ss[i], ss[j]);
                    if(!vist.count(ss)){
                        vist.insert(ss);
                        qu.push(ss);
                    }
                }
            }
            lev++;
        }
        return -1;
    }
};
