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
    using int2=pair<int, int>;
public:
    int count = 0;
    
    int2 dfs(TreeNode* root){
        if(root == NULL)
            return {0,0} ;
        
        
        auto left_sub = dfs(root->left);
        auto right_sub = dfs(root->right);
        
        
        int sum = root->val + left_sub.first + right_sub.first;
        int n = 1 + left_sub.second + right_sub.second; //numberOfNodes
        
        if( sum / n == root->val){
            count++;
        }
        return {sum, n}; 
        // Return the calculated values for the current subtree.
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};