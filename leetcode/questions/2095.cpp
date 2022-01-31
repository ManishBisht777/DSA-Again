ListNode* deleteMiddle(ListNode* head) {
        
        if(!head ) return head;
        if(!head->next) {delete head ; return NULL;}
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next && fast->next->next)       
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next) slow=slow->next;
        
        fast=head;
        while(fast->next!=slow)
        {
            fast=fast->next;
        }
        
        fast->next=slow->next;
        
        return head;
    }