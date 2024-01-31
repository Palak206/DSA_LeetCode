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
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int leftSub = height(root->left);
        int rightSub = height(root->right);
        
        if(leftSub == -1 || rightSub == -1 || abs(leftSub-rightSub) > 1)
            return -1;
        
        return 1+max(leftSub, rightSub);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        if(height(root) == -1)
            return false;
        
        return true;
    }
};