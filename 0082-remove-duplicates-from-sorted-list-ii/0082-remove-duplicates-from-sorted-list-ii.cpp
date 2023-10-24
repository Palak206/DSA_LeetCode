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
//  T.C = O(N) S.C = O(1)
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* dummy = new ListNode(0,head);//dummy node
//         ListNode* prev= dummy;
        
//         while(head!=NULL){
//             if(head->next!=NULL && head->val==head->next->val){
//                 // skip the nodes whose values are equal 3=3
//                while(head->next!=NULL && head->val==head->next->val){
//                    head=head->next;
//                }
//                 prev->next=head->next;
//             }else{
//                 prev=prev->next;
//             }
//             head=head->next;
//         }
//         return dummy->next;

//     }
// };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        //0->10
        
        ListNode* itr = dummy;
        
        while(itr->next != NULL && itr->next->next != NULL){
            if(itr->next->val == itr->next->next->val){
                int var = itr->next->val;
                //1->3->3->4 = 
                while(itr->next != NULL && itr->next->val == var)
                    itr->next = itr->next->next; //delete the node 1->4
            }
            else
                itr = itr->next;
        }
        return dummy->next;
    }
};