class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x= cost.size();
        if(x==2){
            return min(cost[0], cost[1]);
        }
        for(int i=2; i<x; i++){
            cost[i]= cost[i]+ min(cost[i-1], cost[i-2]);
        }
        return min(cost[x-1], cost[x-2]);
    }
};
