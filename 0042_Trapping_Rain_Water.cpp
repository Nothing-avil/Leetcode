#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
        int n=  height.size();
        vector<int> leftmax(n, 0);
        vector<int> rightmax(n, 0);
        int count=0;
        int m1=INT_MIN, m2=INT_MIN;
        for(int i=0; i<n; i++){
            m1 = max(m1, height[i]);
            leftmax[i]= m1;
        }
        for(int i=n-1; i>=0; i--){
            m2 = max(m2, height[i]);
            rightmax[i]= m2;
        }
        for(int i=0; i<n; i++){
            if((min(leftmax[i], rightmax[i])-height[i])>0){
                count= count + (min(leftmax[i], rightmax[i])-height[i]);
            }
        }
        return count;
    }
};
