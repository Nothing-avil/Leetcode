/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
}();
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> qu;
        int ans = 0;
        function<int(vector<int>)> caller = [](vector<int> nums){
            int len = nums.size();
            unordered_map<int, int> map;
            vector<int> alls(nums.begin(), nums.end());
            for (int i = 0; i < len; i++)
                map[nums[i]] = i;
            sort(nums.begin(), nums.end());
            int ans = 0;
            for (int i = 0; i < len; ++i) map[nums[i]] = i;
            for (int i = 0; i < len; ++i) alls[i] = map[alls[i]];
            for (int i = 0; i < len; ++i) {
                while (alls[i] != i) {
                    swap(alls[i], alls[alls[i]]);
                    ++ans;
                }
            }
            return ans;
        };
        qu.push(root);
        while(qu.size()){
            vector<int> check;
            for(int i= qu.size(); i; i--){
                auto it = qu.front();
                qu.pop();
                check.push_back(it->val);
                if(it->left){
                    qu.push(it->left);
                }
                if(it->right){
                    qu.push(it->right);
                }
            }
            ans += caller(check);
        }
        return ans;
    }
};
