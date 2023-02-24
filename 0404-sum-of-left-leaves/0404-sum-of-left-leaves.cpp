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
    int sumOfLeftLeaves(TreeNode* root) {
       // If the tree only contains one node, simply return 0
        // As in the third example of the problem
        if (root->left == NULL and root->right == NULL) return 0;
        // Initializing the answer
        int ans = 0;
        // Performing DFS
        dfs(root, ans);
        return ans;
    }
    void dfs(TreeNode* root, int &ans) {
        // If left node exists and the left node's children are NULLs
        // then it's a left leaf! Append it to the count.
        if (root->left and !root->left->left and !root->left->right) 
            ans += root->left->val;
        
        // Traverse the left subtree
        if (root->left) dfs(root->left, ans);
        // Traverse the right subtree
        if (root->right) dfs(root->right, ans);
    }
    
};