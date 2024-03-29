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
// Diameter = lh+rh
class Solution {
public:
    int height(TreeNode* root, int &diameter){
        if(root == NULL)
            return 0;
        
        int leftSub = height(root->left , diameter);
        int rightSub = height(root->right , diameter);
        
        diameter = max(diameter, leftSub+rightSub);
        
        return 1+max(leftSub, rightSub);
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};