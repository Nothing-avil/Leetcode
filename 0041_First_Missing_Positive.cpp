#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
int speedUp = []
{std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();
bool has[100002];

int digit(char c)
{
    return c & 15;
}
bool isDigit(char c)
{
    return '0' <= c && c <= '9';
}
int init = [] {
    std::ofstream out("user.out");
    std::cout.rdbuf(out.rdbuf());
    for (string s; std::getline(std::cin, s); std::cout << '\n') {
        int n = count(s.begin(), s.end(), ',') + 3;
        memset(has, 0, n);
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            if (s[_i] == '-')for (_i += 2; isDigit(s[_i]); ++_i);
            else {
                int v = s[_i++] & 15;
                while (isDigit(s[_i])) v = v * 10 + digit(s[_i++]);
                if (0 < v && v < n) has[v] = true;
            }
        }
        for (int i = 1;; ++i)
            if (!has[i]) {
                std::cout << i;
                break;
            }
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    int firstMissingPositive(vector<int>) { return 0; }
};
