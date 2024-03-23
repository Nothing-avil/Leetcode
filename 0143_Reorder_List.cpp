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

#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
class Solution {
public:
    ListNode* lol;
    void solve(ListNode* head){
        if(head==NULL){
            return;
        }
        solve(head->next);
        ListNode* temp= lol->next;
        if(lol->next==NULL){
            return;
        }
        else if(head==lol){
            head->next=NULL;
            return;
        }
        lol->next= head;
        head->next= (temp==head)?NULL:temp;

        lol=temp;
    }
    void reorderList(ListNode* head) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        lol= head;
        solve(head);
    }
};
