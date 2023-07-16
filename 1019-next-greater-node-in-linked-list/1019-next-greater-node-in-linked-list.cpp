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
//     vector<int> nextLargerNodes(ListNode* head) {
//         vector<int> l1;
//         while(head){
//             l1.push_back(head->val);
//             head=head->next;
//         }
//         vector<int>res;
//         int maxi;
//         for(int i= 0; i<l1.size() ; i++){
//             if(l1[i] < l1[i+1])
//                 maxi = l1[i+1];
//         }
//         for(int i= 0; i<l1.size() ; i++){
//             if(l1[i] < maxi){
//                 res.push_back(maxi);
//             }
//             else
//                 res.push_back(0);
//         }
//         return res;
//     }
// };

// we have to fing grreater from right so  
// for 7 we have to check greter ele from 4 ->3->5 sp we have to traverse again again
// so t.c = o(n2)

// optimized
//  we have to find right most greater element so 
// we can start from end node no we dont need to traverse gain again
// reverse the list use stack

class Solution {
public:
    ListNode* Reverse(ListNode* head){
        if(head == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode* temp = NULL;
        
        while(head!=NULL){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    vector<int> nextLargerNodes(ListNode* head){
        vector<int>res;
        stack<int>st;
        
        head = Reverse(head);
        //5 3 4 7 2
        while(head != NULL){
            if(st.empty()){
                res.push_back(0); //0
                st.push(head->val);//5
                head = head->next;//3
            }
            else if(st.top() > head->val){//5>3
                res.push_back(st.top());//5
                st.push(head->val);//3
                head = head->next;//4
                
            }
            
            else{
                st.pop();//if no greter element present 7 = 0
            }
            //0 5 5 0 7
        }
        reverse(res.begin() , res.end());//7 0 5 5 0
        return res;
    }
};


