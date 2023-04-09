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
    int deepestLeavesSum(TreeNode* root) {
        int height = maxDepth(root);
        findSum(root , 1 , height);
        return sum;
    }
    int maxDepth(TreeNode* root){
        if(root == NULL)
            return 0;
        
        return 1+max(maxDepth(root->left) , maxDepth(root->right));
    }
    void findSum(TreeNode* root , int curr_Depth , int depth){
        if(root != NULL){
            if(curr_Depth == depth){
                sum += root->val;
            }
            findSum(root->left , curr_Depth+1 , depth); //curdepth+1 bcoz 1 level down
            findSum(root->right , curr_Depth+1, depth);
        }
    }
};