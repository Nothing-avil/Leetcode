#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {

    struct Day {
        int t;
        int i;
    };
    
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<Day, vector<Day>> temps;
        vector<int> res(t.size(), 0);
        for(int i = (int)t.size() - 1; i >= 0; i--) {
            while(!temps.empty() && temps.top().t <= t[i]) {
                temps.pop();
            }
            if(!temps.empty()) {
                res[i] = temps.top().i - i;
            }
            temps.push(Day{t[i], i});
        }
        return res;
    }
};
