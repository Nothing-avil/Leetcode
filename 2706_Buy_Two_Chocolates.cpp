#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int minPrice    = INT_MAX;
        int secMinPrice = INT_MAX;
        
        for(int &price : prices) {
            if(price < minPrice) {
                secMinPrice = minPrice;
                minPrice    = price;
            } else {
                secMinPrice = min(secMinPrice, price);
            }
        }
        
        if(minPrice + secMinPrice > money)
            return money;
        
        return money - (minPrice + secMinPrice);
    }
};
