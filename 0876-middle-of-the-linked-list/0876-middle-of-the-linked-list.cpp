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
//  APPROACH 1
//  T.C = O(n/2) s.c =o(1) 
// class Solution {
// public:

//     ListNode* middleNode(ListNode* head) {
//         ListNode *slow = head , *fast = head;

//         while(slow != NULL && slow->next != NULL){
//             fast = fast->next;
//             slow = slow->next->next;
//         }
//         return fast;


//         // ListNode *slow = head, *fast = head;
//         // while (fast && fast->next){
//         //     slow = slow->next, fast = fast->next->next;
//         // }
//         // return slow;


        
//     }
// };


//  APPROACH 1
// T.C = O(N)+O(N/2)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int i =0;
        ListNode* n = head;
        while(head != NULL)
        {
            i++;
            head = head->next;
        }
        i = i/2+1;
        int k = 1;
        while(k < i)
        {
            k++;
            n = n->next;
            
        }
        return n;
        
    }
};