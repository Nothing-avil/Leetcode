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
    void solve(TreeNode* root, string& s){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val) + "_";
            return;
        }
        solve(root->left, s);
        solve(root->right, s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        string s="";
        string q="";
        solve(root1, s);
        solve(root2, q);
        return s==q;
    }
};
