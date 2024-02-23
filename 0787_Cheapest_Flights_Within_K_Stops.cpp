#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
        const int cont=  0x3f3f3f3f;
        vector<int> dist(n, cont);
        vector<int> copy;
        dist[src]=0;
        for (int i = 0; i < k + 1; ++i) {
            copy= dist;
            for (auto& f : flights) {
                int s= f[0], e=f[1], c= f[2];
                dist[e]= min(dist[e], copy[s]+c);
            }
        }
        return dist[dst]==cont?-1:dist[dst];
    }
};
