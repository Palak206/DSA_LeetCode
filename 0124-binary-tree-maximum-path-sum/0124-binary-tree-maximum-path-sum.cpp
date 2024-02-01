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
    int maxPath(TreeNode* root , int &maxi){  
        if(root == NULL)
            return 0;
        
        int leftNode = max(0 , maxPath(root->left, maxi));
        int rightNode =  max(0 , maxPath(root->right, maxi));
        
        maxi = max(maxi, leftNode+rightNode+root->val);
        
        return max(leftNode, rightNode) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root , maxi);
        return maxi;
    }
};