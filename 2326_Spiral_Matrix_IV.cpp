// ███████╗  █████╗  ███╗   ██╗ ██████╗   █████╗  ██████╗  ██████╗  ██╗  ██╗
// ██╔════╝ ██╔══██╗ ████╗  ██║ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██╔══██╗ ██║  ██║
// ███████╗ ███████║ ██╔██╗ ██║ ██║  ██║ ███████║ ██████╔╝ ██████╔╝ ███████║
// ╚════██║ ██╔══██║ ██║╚██╗██║ ██║  ██║ ██╔══██║ ██╔═██╗  ██╔══██╗ ██╔══██║
// ███████║ ██║  ██║ ██║ ╚████║ ██████╔╝ ██║  ██║ ██║  ██╗ ██████╔╝ ██║  ██║
// ╚══════╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═════╝  ╚═╝  ╚═╝
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        ListNode* temp= head;
        int row_s=0, row_e= m-1;
        int col_s =0, col_e= n-1;
        while(temp){
            while(row_s <= row_e && col_s <= col_e){
                for (int i = col_s; i <= col_e && temp!=NULL; i++) {
                    res[row_s][i]= temp->val;
                    temp= temp->next;
                }
                row_s++;
                for (int i = row_s; i <= row_e && temp!=NULL; i++) {
                    res[i][col_e]= temp->val;
                    temp= temp->next;
                }
                col_e--;
                if (row_s <= row_e) {
                    for (int i = col_e; i >= col_s && temp!=NULL; i--) {
                        res[row_e][i]= temp->val;
                        temp= temp->next;
                    }
                    row_e--;
                }
                if (col_s <= col_e) {
                    for (int i = row_e; i >= row_s && temp!=NULL; i--) {
                        res[i][col_s]= temp->val;
                        temp= temp->next;
                    }
                    col_s++;
                }
            }
        }
        return res;
    }
};
