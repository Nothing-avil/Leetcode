#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
constexpr int LIMIT = 8;

class Solution {
    void bubble_sort(vector<int>& nums, const int begin, const int end) const {
        bool repeat = true;
        while (repeat) {
            repeat = false;
            for (int i = begin; i + 1 < end; i++) {
                if (nums[i + 1] < nums[i]) {
                    swap(nums[i + 1], nums[i]);
                    repeat = true;
                }
            }
        }
    }

    void bubble_sort(vector<int>& nums) const {
        bubble_sort(nums, 0, nums.size());
    }

    void min_max(const vector<int>& nums, int& MIN, int& MAX) const {
        MIN = nums[0];
        MAX = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > MAX)
                MAX = nums[i];
            else if (nums[i] < MIN)
                MIN = nums[i];
        }
    }

    int index(const int MIN, const int MAX, const int size,
              const int val) const {
        return size * (long int)(val - MIN) / (MAX - MIN + 1);
    }

    void bucket_sort(vector<int>& nums, const int MIN, const int MAX) const {
        const int BUCKET = nums.size();
        vector<vector<int>> data(BUCKET);
        for (int i : nums)
            data[index(MIN, MAX, BUCKET, i)].push_back(i);

        int j = 0;
        for (auto& it : data) {
            counting_sort(it);
            for (int i : it)
                nums[j++] = i;
        }
    }

    void counting_sort(vector<int>& nums, const int MIN, const int MAX) const {
        const int BUCKET = MAX - MIN + 1;

        vector<int> data(BUCKET, 0);
        for (int i : nums)
            ++data[i - MIN];

        int k = 0;
        for (int i = 0; i < BUCKET; ++i) {
            for (int j = 0; j < data[i]; ++j)
                nums[k++] = i + MIN;
        }
    }

    void counting_sort(vector<int>& nums) const {
        if (nums.size() < LIMIT) {
            bubble_sort(nums);
            return;
        }

        int MIN, MAX;
        min_max(nums, MIN, MAX);

        counting_sort(nums, MIN, MAX);
    }

    void count_buck_sort(vector<int>& nums) const {
        if (nums.size() < LIMIT) {
            bubble_sort(nums);
            return;
        }

        int MIN, MAX;
        min_max(nums, MIN, MAX);

        if (MAX > nums.size() * log2(nums.size()) + MIN)
            bucket_sort(nums, MIN, MAX);
        else
            counting_sort(nums, MIN, MAX);
    }

public:
    vector<int> sortArray(vector<int>& nums) const {
        count_buck_sort(nums);
        //sort(nums.begin(), nums.end());
        return nums;
    }
};
