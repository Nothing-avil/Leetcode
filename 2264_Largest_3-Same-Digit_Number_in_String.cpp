class Solution {
public:
    string largestGoodInteger(string num) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        char maxs=' ';
        for(int i=1; i<num.size()-1; i++){
            if(num[i-1]==num[i] && num[i]==num[i+1]){
                maxs= max(maxs, num[i]);
            }
        }
        if(maxs==' '){
            return "";
        }
        return string(3, maxs);
    }
};
