// ██╗  ██╗███████╗██╗     ██╗      ██████╗
// ██║  ██║██╔════╝██║     ██║     ██╔═══██╗
// ███████║█████╗  ██║     ██║     ██║   ██║
// ██╔══██║██╔══╝  ██║     ██║     ██║   ██║
// ██║  ██║███████╗███████╗███████╗╚██████╔╝▄█╗
// ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ ╚═════╝ ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n= rating.size();
        int team=0;
        for(int i=1; i<n-1; i++){
            int countsleft=0;
            int countlleft=0;
            int countsright=0;
            int countlright=0;
            for(int j=0; j<i; j++){
                if(rating[j] < rating[i]){
                    countsleft++;
                }
                else if(rating[j] > rating[i]){
                    countlleft++;
                }
            }
            for(int j=i+1; j<n; j++){
                if(rating[i] < rating[j]){
                    countlright++;
                }
                else if(rating[i] > rating[j]){
                    countsright++;
                }
            }
            team += (countlleft*countsright)+(countsleft*countlright);
        }
        return team;
    }
};
