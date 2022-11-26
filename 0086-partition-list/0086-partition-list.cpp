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
// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         vector<int> res;
//         ListNode* curr = head;

//         while(curr != NULL){
//             if(curr->val < x )
//                 res.push_back(curr->val);   
//             curr = curr->next;
//         }

//         curr = head;
//         while(curr != NULL){
//             if(curr->val >= x)
//                 res.push_back(curr->val);   
//             curr = curr->next;
//         }
//         curr = head;
//         int i = 0;
//         while(curr != NULL)
//         {
//             curr->val = res[i];
//             i++;
//             curr=curr->next;
//         }

//         return head;
        
//     }
// };

class Solution{
    public:
    ListNode* partition(ListNode* head, int x){
    ListNode* before = new ListNode(-1);
        ListNode* after = new ListNode(-1);
        ListNode* before_head = before;
        ListNode* after_head = after;

        while(head != NULL){
            if(head->val < x){
                before->next = head;
                before = before->next;
            }
            else{
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = NULL;
        before->next = after_head->next;
        return before_head->next;
        
}
};
