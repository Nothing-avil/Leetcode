class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= garbage.size();
        int res=0, m=-1, p=-1, g=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<garbage[i].size(); j++){
                if(garbage[i][j]=='M'){
                    m=i;
                }
                else if(garbage[i][j]=='P'){
                    p=i;
                }
                else if(garbage[i][j]=='G'){
                    g=i;
                }
                res++;
            }
        }
        for(int i=1; i<travel.size(); i++){
            travel[i]+= travel[i-1];
        }
        res+=m>0?travel[m-1]:0; 
        res+=p>0?travel[p-1]:0; 
        res+=g>0?travel[g-1]:0; 
        return res;
    }
};
