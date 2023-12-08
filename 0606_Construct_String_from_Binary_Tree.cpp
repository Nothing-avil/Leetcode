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
    void preorder(TreeNode* root,string & ans){
        if(root==nullptr){
            return;
        }
        ans+=to_string(root->val);
        if(root->left || root->right){
            ans+="(";
            preorder(root->left,ans);
            ans+=")";
        }
        if(root->right){
            ans+="(";
            preorder(root->right,ans);
            ans+=")";
        }
    }
    string tree2str(TreeNode* root) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        string s="";
        preorder(root, s);
        return s;
    }
};
