#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

//Approch1 using Counting Sort

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> col(3);
        for(int i: nums){
            col[i]++;
        }
        int j=0;
        for(int i=0; i<3; i++){
            while(col[i]--){
                nums[j]=i;
                j++;
            }
        }
    }
};

//Approch2 using Dutch National Flag

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;
        while (mid <= hi) {
            switch (nums[mid]) {
                case 0:
                    swap(nums[lo++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[hi--]);
                    break;
            }
        }
    }
};
