#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
// auto init = []()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 'c';
// }();
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n= arr.size();
        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> min_heap;
        for(int i=0; i<arr.size(); i++){
            min_heap.push({1.0*arr[i]/arr[n-1], (double) i, (double) n-1});
        }
        int val=1;
        while(val<k){
            auto it= min_heap.top();
            min_heap.pop();
            int i= it[1];
            int j= it[2]-1;
            val++;
            min_heap.push({1.0*arr[i]/arr[j], (double) i, (double) j});
        }

        auto dt= min_heap.top();
        return {arr[(int)dt[1]], arr[(int)dt[2]]};
    }
};
