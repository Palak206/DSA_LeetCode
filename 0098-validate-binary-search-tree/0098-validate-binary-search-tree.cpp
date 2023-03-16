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
    bool isValidBST(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return true;        
        return checkBST(root, NULL, NULL); 
    }

    bool checkBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL)
            return true;
        if ((min != NULL && root->val <= min->val) || (max != NULL && root->val >= max->val))
            return false;
        return checkBST(root->left, min, root) &&
               checkBST(root->right, root, max);  
    }
};