class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //hum yh pr cycle in a graph wala concept use karenge.....
        int e=nums[0];
        int a= nums[0];

        a=nums[a];
        e=nums[nums[e]];
        while(e!=a){
            e=nums[nums[e]];
            a=nums[a];
        }
        a=nums[0];
        while(a!=e){
            a=nums[a];
            e=nums[e];
        }
        return a;
    }
};
