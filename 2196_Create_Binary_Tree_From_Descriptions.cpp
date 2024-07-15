#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> vis;
        for (auto& d : descriptions) {
            int p = d[0], c = d[1], left = d[2];
            if (!m.count(p)) m[p] = new TreeNode(p);
            if (!m.count(c)) m[c] = new TreeNode(c);
            if (left)
                m[p]->left = m[c];
            else
                m[p]->right = m[c];
            vis.insert(c);
        }
        for (auto& [v, node] : m) {
            if (!vis.count(v)) return node;
        }
        return nullptr;
    }
};
