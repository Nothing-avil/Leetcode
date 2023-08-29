struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *L3, *l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    L3=l3;
    int c=0;
    while(l1!=NULL || l2!=NULL){
        int s=c;
        if(l1!=NULL){
            s=s+l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            s= s + l2->val;
            l2=l2->next;
        }
        c=s/10;
        s=s%10;
        struct ListNode *n=(struct ListNode*)malloc(sizeof(struct ListNode));
        n->val=s;
        n->next=NULL;
        L3->next=n;
        L3=L3->next;
    }
    if(c>0){
        struct ListNode *n=(struct ListNode*)malloc(sizeof(struct ListNode));
        n->val=c;
        n->next=NULL;
        L3->next=n;
    }
    return l3->next;
}
