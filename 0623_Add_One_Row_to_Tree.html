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

    TreeNode* solve(TreeNode* root, int val, int depth, int c){
        if(root==NULL){
            return NULL;
        }

        if(c==depth-1){
            TreeNode* leftside= root->left;
            TreeNode* rightside= root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left= leftside;
            root->right->right= rightside;

            return root;
        }
        root->left= solve(root->left, val, depth, c+1);
        root->right= solve(root->right, val, depth, c+1);
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node= new TreeNode(val);
            node->left= root;
            return node;
        }
        int c=1;
        return solve(root, val, depth, c);
    }
};
