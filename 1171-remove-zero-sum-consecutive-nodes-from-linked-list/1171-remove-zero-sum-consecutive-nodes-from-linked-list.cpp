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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        vector<int>arr;
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        
        //  Remove all sublists with zero sum
        for(int i=0; i<arr.size(); i++){
            int sum = 0;
            for(int j=i; j<arr.size(); j++){
                sum += arr[j];
                if(sum == 0){
                    // Found a sublist with zero sum, remove it
                    arr.erase(arr.begin() + i, arr.begin() + j + 1);
                    i--; // Go back one step to check the previous sublist
                    break;
                }
            }
            
        }
        
        if(arr.empty()) 
            return NULL;
        
        ListNode* ans = new ListNode(arr[0]); //creating head 
        ListNode* mover = ans; //pointer pointing towards head
        for (int i=1; i<arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]); //creating new node every time
            mover->next=temp; //pointing mover to temp
            mover=mover->next; //moving mover to the next node
        }
        return ans;
        
    }
};