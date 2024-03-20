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
//ath node k phle bala node a-1
// bth k bad bala node b+1
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* left = NULL;
        ListNode* right = list1;
        
        for(int i = 0; i<=b; i++){
            if(i == a-1){
                left = right; //13
            }
            right = right->next; //5
        }
        left->next = list2;
        ListNode* temp = list2;
        
        while(temp != NULL && temp->next != NULL){
            temp = temp->next; // 10002
        }
        temp->next = right;
        
        return list1;
    }
};