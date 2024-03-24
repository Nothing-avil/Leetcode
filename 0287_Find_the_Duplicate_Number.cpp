// 1st Approach
#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int arr[100010]={0};
        for(int i=0; i<nums.size(); i++){
            arr[nums[i]]++;
            if(arr[nums[i]]>1){
                return nums[i];
            }
        }
        return -1;
    }
};

// 2nd Approach
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
