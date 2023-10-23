class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0 && not(n & n-1) && n%3 == 1);
    }
};
