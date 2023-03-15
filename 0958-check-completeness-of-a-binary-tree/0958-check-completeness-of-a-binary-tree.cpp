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
// Approach : Breadth First Search
// Traverse the tree in level-order using a queue. At each level, we add the left and right child nodes of each node to the queue.
// If we encounter a null node, we still add it to the queue so that we can check if there are any more nodes left in the next step.
// Once we have traversed the entire tree, we check if there are any remaining nodes in the queue.
// If there are, it means the tree is not complete, and we return false.
// Otherwise, the tree is complete, and we return true.
// Complexity :
// Time complexity : O(n)
// Space complexity: O(n) maximum width

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)
            return true;
        
        queue<TreeNode*>q;
        q.push(root);
        
        bool gotNullSoFar = false;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node==NULL){
                gotNullSoFar = true;
            }else{
                if(gotNullSoFar==true) return false; //remaining node
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
        
        
        
    }
};