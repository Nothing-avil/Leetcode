class Solution {
public:
    int find(int x){
        int count=0;
        while(x!=0){
            count += 1&x;
            x=x>>1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        auto cmp =[&](int &a, int &b){
            int ca= find(a);
            int cb= find(b);

            if(ca==cb){
                return a<b;
            }
            return ca<cb;
        };
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
