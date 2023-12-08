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

//preorder
// if node left empty and node right is present we add empty parenthisis ()
// 2nd ex 1(2()(4)())(3()()) = 1(2()(4))(3)

class Solution {
public:
    string s = "";
    void pre(TreeNode* root){
        if(root == NULL){
            return ;
        }
        
        s += to_string(root->val);
        
        //if node has left and right child then add parenthisis
        if(root->left != NULL || root->right != NULL){
            s += '(';
            pre(root->left);
            s += ')';
        }
        
        //if node has right child  and left empty then add parenthisis
        if(root->right != NULL){
            s += '(';
            pre(root->right);
            s += ')';
        }
    }
    
    string tree2str(TreeNode* root) {
        pre(root);
        return s;
    }
};