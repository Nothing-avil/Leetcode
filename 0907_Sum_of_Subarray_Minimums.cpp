#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
typedef unsigned long long ll;
class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& a) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int stackSum=a.front(),ans=a.front();
        stack<pair<int,int>> st;
        st.push({a.front(),1});
        for(int i=1;i<a.size();i++){
            pair<int,int> p={a[i],1};
            while(!st.empty() && st.top().first>=a[i]){
                auto [x,y]=st.top();
                stackSum-=x*y;
                p.second+=y;
                st.pop();
            }
            stackSum+=p.first*p.second;
            ans=(ans+0LL+stackSum)%mod;
            st.push(p);
        }
        return ans;
        
    }
};
