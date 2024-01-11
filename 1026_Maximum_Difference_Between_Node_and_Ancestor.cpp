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
class Solution {
public:
    int solve(TreeNode* root, int mins, int maxx){
        if(root==NULL){
            return abs(mins-maxx);
        }
        mins= min(mins, root->val);
        maxx= max(maxx, root->val);
        int l= solve(root->left, mins, maxx);
        int r= solve(root->right, mins, maxx);
        return max(l, r);
    }
    int maxAncestorDiff(TreeNode* root) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        return solve(root, root->val, root->val);
    }
};
