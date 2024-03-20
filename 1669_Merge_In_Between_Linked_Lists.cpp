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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        ListNode* temp1;
        ListNode* temp2;
        temp1= temp2= list1;
        for(int i=0; i<a-1; i++){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1=temp1->next;
        temp2->next= list2;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        for(int i=a; i<b; i++){
            temp1=temp1->next;
        }
        temp2->next=temp1->next;
        return list1;
    }
};
