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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> grp(k, nullptr);
        int i=0;
        ListNode *temp;
        temp=head;
        while(temp){
            i++;
            temp = temp->next;
        }
        int l=i%k;
        int s=i/k;
        temp=head;
        ListNode* temp1=nullptr;

        for (int i = 0; i < k && temp; i++) {
            grp[i] = temp;
            
            int currentPartSize = s + (i < l ? 1 : 0);
            
            for (int j = 0; j < currentPartSize; j++) {
                temp1 = temp;
                temp = temp->next;
            }
            
            if (temp1) temp1->next = nullptr;
        }

        return grp;
    }
};
