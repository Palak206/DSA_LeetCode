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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k == 0)
          return head;
        
        int cnt = 0;
        ListNode* temp = head;
        // count the no. of node
        //reach the last elemet after rotating
        // our last element is connected to head (5->1)
        while(temp->next!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
//         if k= 0 then we don't reverse it we return as it as
        
        
         //2nd test case size = 2 and k= 4 if we rotate it 4 times
        //the result will same as that we get in 1st times
        
          k=k%(cnt+1);
        // temp = 5 last element
        // now we connect it's next to the head 5->1
        temp->next = head;
        
        //cnt = 4
        int jump = cnt - k;//4-2= 2  
        temp = head;
        // int i=1;
        while(jump)
        {
            temp=temp->next;
            jump--;
        }
         // temp = 3
        //we want to save 4->5
        ListNode* prev = temp->next; // 4
        temp->next = NULL; // 3 ->null
        return prev;
    }
};