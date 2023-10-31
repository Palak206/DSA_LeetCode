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
//     ListNode* removeNthFromEnd(ListNode* head, int n) {

//         ListNode* fast = head;
//         ListNode* slow = head;

//         for(int i =1 ; i<=n ; i++){
//             fast = fast->next;
//         }
        
//         if(fast==NULL){
//             return head->next;
//         }
        
//         while(fast->next != NULL){
//             fast = fast->next;
//             slow = slow->next;
//         }

//         slow->next = slow->next->next;

//         return head;
        


//     }
// };

// reverse the linkedlist 5 - 4 - 3 - 2 - 1
// traverse until n = 0 
class Solution {
    ListNode* reverse(ListNode* head){
        ListNode* curr = head , *temp;
        ListNode* prev = NULL;

        while(curr != NULL){
            temp = curr->next ;
            curr->next = prev;
            prev = curr;
            curr= temp;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        //create dummy node
        ListNode* dummy =  new ListNode(0);
        ListNode* curr = dummy;
        curr->next = reverse(head);
        // 0-5-4-3-2-1

    //    while(curr) curr = curr -> next;
        if(n==0){
         head = head->next;
         return head;
        }

        // ListNode* prev = NULL;
        // curr = head;
        int count=0;
        ListNode* prev =NULL;
        while(count<n && curr!=NULL)  //TRAVERSING UNTIL WE FIND THE REQUIRED NODE
        {
            prev=curr;
            curr=curr->next;
            count++;
            
        }
        
        prev->next=curr->next;        //REMOVING THE NODE
        curr->next=NULL;
        return reverse(dummy->next);     //REVERSING AGAIN (EXCLUDING THE DUMMY NODE)
        // 1 2 3 5
    }
};

// class Solution{
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
// 	ListNode* curr = head;
// 	int len = 0, i = 1;
// 	while(curr) 
//        curr = curr -> next, len++;    // finding the length of linked list
// 	if(len == n)
//        return head -> next;       
//         // if head itself is to be deleted, just return head -> next

// 	for(curr = head; i < len - n; i++) {
//           curr = curr -> next;
//     } // iterate first len-n nodes
// 	curr -> next = curr -> next -> next;      // remove the nth node from the end
// 	return head;
// }
// };