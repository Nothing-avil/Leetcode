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

    int solve(vector<string>& t1, vector<string>& t2){
        int i=0;
        while(i<t1.size() || i<t2.size()){
            int a=(i<t1.size())?stoi(t1[i]):0;
            int b=(i<t2.size())?stoi(t2[i]):0;
            if(a > b){
                return 1;
            }
            else if(a < b){
                return -1;
            }
            else{
                i++;
            }
        }
        return 0;
    }

    int compareVersion(string v1, string v2) {
        vector<string> t1, t2;
        string str1, str2;
        stringstream ss(v1);
        stringstream s(v2);
        while (getline(ss, str1, '.')){
            t1.push_back(str1);
        }
        while (getline(s, str2, '.')){
            t2.push_back(str2);
        }
        
        return solve(t1, t2);
    }
};
