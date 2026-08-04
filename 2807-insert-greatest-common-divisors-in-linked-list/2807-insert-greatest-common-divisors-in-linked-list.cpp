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
    int gcd(int a,int b)
    {
        if(b==0) return a;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;
        ListNode* forward=head->next;
        while(forward!=NULL){
            int hcf=gcd(curr->val,forward->val);
            ListNode* temp=new ListNode(hcf);
            curr->next=temp;
            temp->next=forward;
            curr=temp->next;
            forward=curr->next;
        }   
        return head;
    }
};