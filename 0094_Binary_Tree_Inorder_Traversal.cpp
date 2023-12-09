#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<int> vec;
        stack<TreeNode*> st;
        TreeNode* temp= root;
        while(temp!=NULL || st.empty()==false){
            while(temp!=NULL){
                st.push(temp);
                temp=temp->left;
            }
            temp= st.top();
            st.pop();
            vec.push_back(temp->val);
            temp=temp->right;
        }
        return vec;
    }
};
