
class Solution {
public:
    vector<int> res;
    void guts(TreeNode* root, int D){
        if(root== NULL){
            return;
        }
        if(res.size()== D){
            res.push_back(root->val);
        }
        else{
            res[D]= max(res[D], root->val);
        }
        guts(root->left, D+1);
        guts(root->right,D+1);
    }
    vector<int> largestValues(TreeNode* root) {
        guts(root, 0);
        return res;
    }
};
