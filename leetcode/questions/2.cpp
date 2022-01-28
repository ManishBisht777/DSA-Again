ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ans(0);
        ListNode *temp=&ans;
        int extra=0;
        
        while(l1 || l2 || extra)
        {
            if(l1) extra+=l1->val , l1=l1->next;
            if(l2) extra+=l2->val , l2=l2->next;
            
            temp->next=new ListNode(extra%10);
            extra=extra/10;
            temp=temp->next;
        }
        
        return ans.next;
    }