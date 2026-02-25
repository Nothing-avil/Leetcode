// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
};

//First Approach

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            int aa = __builtin_popcount(a);
            int bb = __builtin_popcount(b);
            if(aa == bb){
                return a < b;
            }
            return aa < bb;
        });
        return arr;
    }
};

//Second Approach

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
