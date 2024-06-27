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
    int findCenter(vector<vector<int>>& edges) {
        int nodes[4];
        nodes[0] = edges[0][0];
        nodes[1] = edges[0][1];
        nodes[2] = edges[1][0];
        nodes[3] = edges[1][1];
        std::ranges::sort(nodes);
        for (int i = 0; i <= 2; ++i)
            if (nodes[i] == nodes[i + 1])
                return nodes[i];
        return {};
    }
};
