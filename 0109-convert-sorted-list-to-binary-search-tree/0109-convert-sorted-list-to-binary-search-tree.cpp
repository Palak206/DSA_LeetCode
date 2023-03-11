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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      vector<int> v;
      while (head) {
        v.push_back(head->val);
        head = head->next;
    }
  
    return fnc(v ,0 , v.size()-1);
    }
        
        
    TreeNode* fnc(vector<int>& v , int low , int high){  
         if(low<=high){
            int mid = low + (high-low)/2;
            TreeNode* root = new TreeNode(v[mid]);
            root->left = fnc(v, low, mid-1);
            root->right = fnc(v, mid+1, high);
            return root;
        }
        return NULL;
    }
};

// class Solution {
// public:
//     TreeNode* buildBST(ListNode* head) {
//         if(!head) return nullptr;

//         ListNode *slow = head, *fast = head, *prev = nullptr;
 
//         while(fast && fast->next) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         if(prev) prev -> next = nullptr;
//         if(slow == head) head = nullptr;

//         TreeNode* node = new TreeNode(slow->val);

//         node -> left = buildBST(head);
//         node -> right = buildBST(slow->next);

//         return node;
//     }

//     TreeNode* sortedListToBST(ListNode* head) {
//         return buildBST(head);
//     }
// };
