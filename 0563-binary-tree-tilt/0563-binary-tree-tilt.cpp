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
    int sum = 0;
    int dfs(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        
        sum += abs(leftSum - rightSum);
        //return total sum;
        return root->val + leftSum + rightSum;
    }
    
    int findTilt(TreeNode* root) {
        dfs(root);
        return sum;
    }
};