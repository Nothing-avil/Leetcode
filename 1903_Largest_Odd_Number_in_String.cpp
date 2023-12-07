static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
class Solution {
public:
    string largestOddNumber(string num) {
        int n= num.length();
        while(n--){
            if(num[n]=='1' || num[n]=='3' || num[n]=='5' ||num[n]=='7' || num[n]=='9'){
                return num.substr(0,n+1);
            }
        }
        return "";
    }
};
