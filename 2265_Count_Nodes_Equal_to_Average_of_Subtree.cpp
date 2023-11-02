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
    int res;
    pair<int, int> solve(TreeNode* root){
        if(!root){
            return {0, 0};
        }
        auto a= solve(root->left);
        auto b= solve(root->right);
        int sum= a.first+b.first+root->val;
        int c= a.second+b.second+1;
        int avgn= (sum/c);
        if(avgn==root->val){
          res+=1;
        }
        return {sum, c};
    }
    int averageOfSubtree(TreeNode* root) {
        res=0;
        solve(root);
        return res;
    }
};
