class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int l = nums.size();
        for (int i = 0; i < l; ++i) {
            int x = nums[i];
            int r = target - x;
            if (m.count(r)) {
                return {m[r], i};
            }
            m[x] = i;
        }
        return {};
    }
};
