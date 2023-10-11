class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n= flowers.size();
        vector<int>s(n);
        vector<int>e(n);
        for(int i=0; i<n; i++){
            s[i]= flowers[i][0];
            e[i]= flowers[i][1];
        }
        sort(begin(s), end(s));
        sort(begin(e), end(e));
        vector<int>res(people.size());
        for(int i=0; i<people.size(); i++){
            int x= upper_bound(begin(s), end(s), people[i]) - begin(s);
            int y= lower_bound(begin(e), end(e), people[i]) - begin(e);
            res[i]=x-y;
        }
        return res;
    }
};
