/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
        }
    }
    struct ListNode* prev=NULL;
    struct ListNode* curr=slow;
    struct ListNode* forward=NULL;
    
     while(curr!=NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;            
        }
        int ans=0;
      struct  ListNode* first=head;
       struct ListNode* second=prev;
        while(second!=NULL)
        {
            if(ans<(first->val+second->val))
                ans=first->val+second->val;
            
            first=first->next;
            second=second->next;
        }
        return ans;

}