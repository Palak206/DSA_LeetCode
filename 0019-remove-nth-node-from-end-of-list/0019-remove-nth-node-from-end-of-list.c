/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
  struct ListNode* h1=head, *h2=head;
    while(n-->0) h2=h2->next;
    if(h2==NULL)
        return head->next;  // The head need to be removed, do it.
    h2=h2->next;
    
    while(h2!=NULL){
        h1=h1->next;
        h2=h2->next;
    }
    h1->next=h1->next->next;   // the one after the h1 need to be removed
    return head;
}
