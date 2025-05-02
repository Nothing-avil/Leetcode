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
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string answer(n, ' ');
        vector<int> lefttoright(n, -1), righttoleft(n, -1);
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R'){
                lefttoright[i] = i;
            }
            else if(dominoes[i] == 'L'){
                continue;
            }
            else{
                lefttoright[i] = i > 0 ? lefttoright[i-1] : -1;;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L'){
                righttoleft[i] = i;
            }
            else if(dominoes[i] == 'R'){
                continue;
            }
            else{
                righttoleft[i] = i < n-1 ? righttoleft[i+1] : -1;
            }
        }
        for(int i=0; i<n; i++){
            int distlr = abs(i - lefttoright[i]);
            int distrl = abs(i - righttoleft[i]);
            if(righttoleft[i] == lefttoright[i]){
                answer[i] = '.';
            }
            else if(lefttoright[i] == -1){
                answer[i] = 'L';
            }
            else if(righttoleft[i] == -1){
                answer[i] = 'R';
            }
            else if(distlr == distrl){
                answer[i] = '.';
            }
            else{
                answer[i] = (distlr < distrl) ? 'R' : 'L';
            }
        }
        return answer;
    }
};
