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
    vector<int>res;
    int cval=0;
    int fre=0;
    int maxfre=0;
    void order(TreeNode* root){
        if(root==NULL){
            return;
        }
        order(root->left);
        if(cval==root->val){
            fre++;
        }
        else{
            cval=root->val;
            fre=1;
        }
        if(fre>maxfre){
            res={};
            maxfre= fre;
        }
        if(fre==maxfre){
            res.push_back(root->val);
        }
        order(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        order(root);
        
        return res;
    }
};
