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
    bool isEvenOddTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            int mx = INT_MIN , mn = INT_MAX;
            while(size--)
            {
                TreeNode* front = q.front();  q.pop();
                if(front->left)  q.push(front->left);
                if(front->right)  q.push(front->right);
                if(level % 2 == 0)
                {
                    if(!(front->val % 2))  return false;
                    if(front->val > mx)  mx = front->val;
                    else return false;
                }
                else
                {
                    if(front->val % 2)  return false;
                    if(front->val < mn)  mn = front->val;
                    else return false;
                }
            }
            level++;
        }
        return true;
    }
};
