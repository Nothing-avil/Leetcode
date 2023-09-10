class Solution {
public:
    int countOrders(int n) {
       const int MOD = 1e9 + 7;
    
        long long result = 1;
        for (int i = 1; i <= n; i++) {
            result = (result * (2 * i - 1) * i) % MOD;
        }

        return static_cast<int>(result);
    }
};
