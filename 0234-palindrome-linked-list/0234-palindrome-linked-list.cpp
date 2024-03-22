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

//  APPROACH 1 T.C S.C = O(N)
// class Solution {
//     private:
//     bool checkPalindrome(vector<int> arr){
//         int n = arr.size();
//         int s = 0;
//         int e = n-1;

//         while(s <= e){
//             if(arr[s] != arr[e]){
//                 return false;
//             }
//             s++;
//             e--;

//         }
//         return true;
//     }
// public:

//     bool isPalindrome(ListNode* head) {
//         vector<int> arr;
//         ListNode* temp =head;
//         while(temp != NULL){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         return checkPalindrome(arr);
//         arr = curr->next;
        
        
//     }
// };


// class Solution {
//  private:
//     // find the mid
//     ListNode* getMid(ListNode* head){
//         ListNode* slow = head;
//         ListNode* fast = head->next;

//         while(fast != NULL && fast->next != NULL){
//             fast = fast->next->next;
//             slow = slow->next;
//         }
        
//         return slow;

//     }
//     // reverse
//     ListNode* reverse(ListNode* head){
//         ListNode* curr = head;
//         ListNode* prev = NULL;
//         ListNode* temp = NULL;

//         while(curr!=NULL){
//             temp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = temp;

//         }
//         return prev;
    
//     }
// public:
//     bool isPalindrome(ListNode* head){
//         if(head == NULL || head->next == NULL)
//          return true;
// //      find mid
//         ListNode* middle = getMid(head);

//         // step-2 reverse list after mid 1 2 3- (1 2 3)
//         ListNode* temp = middle->next;
//         middle->next = reverse(temp);

//         // step 3 compare both the halfs (1 2 3)- (1 2 3)
//         ListNode* head1 = head;
//         ListNode* head2 = middle->next;

//         while(head2 != NULL){
//             if(head1->val != head2->val){
//                 return false;
//             }
//             head1 = head1->next;
//             head2 = head2->next;

//         }
//         // step 4 - step 2 repeat
//         temp = middle->next;
//         middle->next = reverse(temp);

//         return true;

//     }
// };


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        
        stack<int> st;

        while(temp) {
            st.push(temp->val);
            temp = temp->next;
        }
        bool res = false;
        temp = head;
        while(temp) {
            if(temp->val == st.top()) {
                res = true;
                st.pop();
                temp = temp->next;
            }
            else {
                return false;
            }
        }
        return res;

    }
};
