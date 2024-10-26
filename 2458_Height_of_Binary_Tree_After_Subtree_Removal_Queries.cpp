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
class Solution {
public:
    int maxhei[100001];
    int maxh = 0;

    void heightlr(TreeNode* root, int d){
        if(!root){
            return;
        }
        maxhei[root->val] = maxh;
        maxh = max(maxh, d);
        heightlr(root->left, d+1);
        heightlr(root->right, d+1);
    }
    void heightrl(TreeNode* root, int d){
        if(!root){
            return;
        }
        maxhei[root->val] = max(maxhei[root->val], maxh);
        maxh = max(maxh, d);
        heightrl(root->right, d+1);
        heightrl(root->left, d+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        heightlr(root, 0);
        maxh = 0;
        heightrl(root, 0);
        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            ans[i] = maxhei[queries[i]];
        }
        return ans;
    }
};
