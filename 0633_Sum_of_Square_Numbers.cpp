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
    bool judgeSquareSum(int c) {
        // Approch 1
        for (long long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int)b) {
                return true;
            }
        }
        return false;

        // Approch 2
        long long a = 0;
        long long b = sqrt(c);
        while (a <= b) {
            long long k = a * a + b * b;
            if (k < c) {
                a++;
            } else if (k > c) {
                b--;
            } else {
                return true;
            }
        }
        return false;
    }
};
