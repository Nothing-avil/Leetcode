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
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1, right = position[position.size() - 1];
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(position, mid, m))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }

    bool check(vector<int>& position, int f, int m) {
        int prev = position[0];
        int cnt = 1;
        for (int i = 1; i < position.size(); ++i) {
            int curr = position[i];
            if (curr - prev >= f) {
                prev = curr;
                ++cnt;
            }
        }
        return cnt >= m;
    }
};
