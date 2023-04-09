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
// T.C = O(2N)
// S.C = O(1)
// class Solution {
// public:
//     int sum = 0;
//     int deepestLeavesSum(TreeNode* root) {
//         int height = maxDepth(root);
//         findSum(root , 1 , height);
//         return sum;
//     }
//     int maxDepth(TreeNode* root){
//         if(root == NULL)
//             return 0;
        
//         return 1+max(maxDepth(root->left) , maxDepth(root->right));
//     }
//     void findSum(TreeNode* root , int curr_Depth , int depth){
//         if(root != NULL){
//             if(curr_Depth == depth){ //initially curr_depth = 1
//                 sum += root->val;
//             }
//             findSum(root->left , curr_Depth+1 , depth); 
              //curdepth+1 bcoz 1 level down
//             findSum(root->right , curr_Depth+1, depth);
//         }
//     }
// };

// T.C = O(N) , S.C = O(1)
class Solution {
    int sum  = 0;
    int maxDepth = 0;
    public:
    int deepestLeavesSum(TreeNode* root) {
        findSum(root, 1);
        return sum;
    }
    
    
     void findSum(TreeNode* node, int curr) {
        if(node != NULL) {
            if(curr > maxDepth) {
                sum = 0;
                maxDepth = curr;
            }
            if(curr == maxDepth) {
                sum+=node->val;
            }
            findSum(node->left, curr+1);
            findSum(node->right, curr+1);
        }
    }
};