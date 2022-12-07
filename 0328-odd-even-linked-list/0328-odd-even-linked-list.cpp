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
//     ListNode* oddEvenList(ListNode* head) {
//         if(!head) return head;
//         ListNode* evenHead = new ListNode(-1), *oddHead = new ListNode(-1), *even = evenHead, *odd = oddHead;
//         while(head)
//         {
//             if(head->val % 2 == 0)
//             {
//                 even->next = head;
//                 even = even->next;
//             }
//             else
//             {
//                 odd->next = head;
//                 odd = odd->next;
//             }
//             head = head->next;
//         }
//         even->next = NULL;
//         odd->next = evenHead->next;
//         return oddHead->next;
    
//     }
// };


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = NULL, *headodd = NULL, *even = NULL, *headeven = NULL;
        
        if(!head || !head->next || !head->next->next) return head;
         
        odd = head; headodd = odd;
        even = head->next; headeven = even;
        
        while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = headeven;
        return headodd;
    }  
};