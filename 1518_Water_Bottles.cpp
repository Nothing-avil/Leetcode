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
    int numWaterBottles(int numBottles, int numExchange) {
        int res= numBottles;
        while(numBottles>=numExchange){
            res+= numBottles/numExchange;
            numBottles = numBottles/numExchange + numBottles%numExchange;
        }
        return res;
    }
};
