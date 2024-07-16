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

#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:

    TreeNode* lca(TreeNode* root, int s, int t){
        if(root ==NULL || root->val== s || root->val ==t){
            return root;
        }
        TreeNode* l = lca(root->left, s, t);
        TreeNode* r = lca(root->right, s, t);
        if(l!=NULL && r!=NULL){
            return root;
        }
        return l==NULL ? r:l;
    }

    bool dfs(TreeNode* root, int t, string &st){
        if(root==NULL){
            return false;
        }
        if(root->val == t){
            return true;
        }
        st.push_back('L');
        if(dfs(root->left, t, st)){
            return true;
        }
        st.back()= 'R';
        if(dfs(root->right, t, st)){
            return true;
        }
        st.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA= lca(root, startValue, destValue);
        string start, end;
        dfs(LCA, startValue, start);
        dfs(LCA, destValue, end);
        return string(start.size(), 'U') + end;
    }
};
