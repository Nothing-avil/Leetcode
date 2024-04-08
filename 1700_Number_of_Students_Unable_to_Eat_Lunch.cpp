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
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int arr[2]={0};
        for(int i: students){
            arr[i]++;
        }
        for(int i=0; i<sandwiches.size(); i++){

            if(arr[sandwiches[i]]==0){
                return students.size()-i;
            }

            if(sandwiches[i]==1){
                arr[1]--;
            }
            else{
                arr[0]--;
            }
            
        }
        return 0;
    }
};
