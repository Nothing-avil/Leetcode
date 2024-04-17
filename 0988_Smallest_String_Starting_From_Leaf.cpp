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
    
    void solve(TreeNode* root, string& res, string ans){
        if(root==NULL){
            return;
        }

        ans= char(root->val+'a')+ans;
        if(root->left==NULL && root->right==NULL){
            if(res=="" || res > ans){
                res=ans;
            }
            return;
        }
        solve(root->left, res, ans);
        solve(root->right, res, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string res="";
        solve(root, res, "");
        return res;
    }
};
