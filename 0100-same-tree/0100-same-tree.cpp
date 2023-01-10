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
// O(N) time complexity
// Space complexity -->O(H)H=height of binary tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) {
            return false;
        }
        
        if(p==NULL && q==NULL) {
            return true;
        }
        
        if(p!=NULL && q!=NULL)
        {   
            bool left=isSameTree(p->left, q->left);
            bool right=isSameTree(p->right, q->right);
            if(left && right && p->val==q->val) 
                return true;
        }
        
        //if none of the above case is true i.e value of p and q are not equal
        return false;
    }
};

 
// class Solution {
//     public:
//      bool isSameTree(TreeNode* p, TreeNode* q){
//         if(p == NULL || q == NULL){
//             return(p == q);
//         }
//          return(p->val == q->val) && isSameTree(p->left , q->left) && 
//              isSameTree(p->right , q->right);
             
//     }
    
// };
