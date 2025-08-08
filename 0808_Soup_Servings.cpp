// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    double soupServings(int n) {
        double dp[200][200] = {0.0};
        function<double(int , int)> solve = [&](int A, int B) ->double{
            if(A <= 0 && B <= 0){
                return (0.5);
            }
            if(A <= 0){
                return (1.0);
            }
            if(B <= 0){
                return 0.0;
            }
            if(dp[A][B] > 0.0){
                return dp[A][B];
            }
            double a = 0.0;
            a += solve(A - 4, B);
            a += solve(A - 3, B - 1);
            a += solve(A - 2, B - 2);
            a += solve(A - 1, B - 3);

            return dp[A][B] = (0.25) * (a);
        };
        if(n >= 4300){
            return 1;
        }
        double result = solve(ceil(n/25.0), ceil(n/25.0));
        return result;
    }
};
