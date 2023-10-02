// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
//         ListNode *p1 = head1;
//         ListNode *p2 = head2;

//         if(p1 == NULL || p2 == NULL)
//           return NULL;

//         while( p1 != p2){
//             // if(p1 == p2)
//             //  return p1;

//              if(p1 == NULL){
//               p1 = head2;
//             }

//             else{
//                 p1 = p1->next;
//             }

//             if(p2 == NULL){
//               p2 = head1;
//             }

//             else{
//                 p2 = p2->next;
//             }

//         }

//         return p1;
//     }
// };

//find the length of both the list 
// Traverse the bigger linked list until the remaining nodes count becomes equal to the smaller one's.
// Traverse both the heads together. If both of them are same then the intersecting node is found.

class Solution {
public:
    int length(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        if(!headA || !headB)
            return NULL;
        
        int len1 = length(headA);
        int len2 = length(headB);
        
        if(len1 > len2){
            while(len1 > len2){
                headA = headA->next;
                len1--;
            }
        }
        else if(len1 < len2){
            while(len1 < len2){
                headB = headB->next;
                len2--;
            }
        }
        
        while(headA && headB){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};