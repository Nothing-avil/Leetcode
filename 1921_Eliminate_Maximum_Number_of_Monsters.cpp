class Solution {
public:
    int kill=1;
    int t=1;
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
        int n= dist.size();
        vector<int> time(n);
        for(int i=0; i<n; i++){
            time[i]= ceil((float)dist[i]/speed[i]);
        }
        sort(begin(time), end(time));
        for(int i=0; i<n-1; i++){
            if(time[i+1]<=t){
                return kill;
            }
            kill++;
            t++;
        }
        return kill;
    }
};
