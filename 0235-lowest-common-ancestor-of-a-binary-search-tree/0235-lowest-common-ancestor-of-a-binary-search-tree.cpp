/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (root == NULL || root == p || root == q) {
//             return root;
//         }
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);

//         //result
//         if(left == NULL) {
//             return right;
//         }
//         else if(right == NULL) {
//             return left;
//         }
//         else { //both left and right are not null, we found our result
//             return root;
//         }  
        
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) 
            return NULL;
        
        //if both the p and q is less than root vl then we can find our ans in root left
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left , p, q);
        }
        
        //if both re greatr than root then go right
        else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p , q);
        }
        
        // if both not satisfy then return root the ans
        else{
            return root;
        }
            
    }
};
