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
    int result=INT_MIN;
    int solve(TreeNode* root, int start){
        if(root==NULL){
            return 0;
        }
        int lh= solve(root->left, start);
        int rh= solve(root->right, start);
        if(root->val==start){
            result = max(lh, rh);
            return -1;
        }
        else if(lh>=0 && rh>=0){
            return max(lh, rh)+1;
        }
        else{
            int x= abs(lh)+ abs(rh);
            result = max(result, x);
            return min(lh, rh)-1;
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        solve(root, start);
        return result;
    }
};
