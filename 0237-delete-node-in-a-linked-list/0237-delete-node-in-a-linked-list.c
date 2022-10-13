/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    
//            node -> val = node -> next ->val;
//            node->next = node -> next ->next;
  //}

     struct ListNode* ptr,*temp;
     temp=node;
     while(temp->next->next!=NULL)
     {
         temp->val=temp->next->val;
         temp=temp->next;
     }
     temp->val=temp->next->val;
     ptr=temp->next;
     temp->next=NULL;
     free(ptr);
}
