static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    bool isMonotonic(vector<int> &nums)
    {
        bool init = false;
        bool inc;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                continue;

            bool comp = nums[i] > nums[i - 1];
            if (!init)
            {
                init = true;
                inc = comp;
            }
            else if (inc != comp)
                return false;
        }

        return true;
    }
};
