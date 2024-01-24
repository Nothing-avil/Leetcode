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
    int solve(TreeNode* root, int count) {
        if(!root){
            return 0;
        }
        count ^= 1 << root->val;
        if(!root->left && !root->right) {
            return (count & (count - 1))==0 ? 1:0;
        }
        
        return (solve(root->left, count) + solve(root->right, count));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        return solve(root, 0);
    }
};
