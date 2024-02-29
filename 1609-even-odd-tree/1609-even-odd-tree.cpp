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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* curr = root;
        q.push(curr);
        
        bool even_level = true; // phla level = 0 true
        
        while(!q.empty()){
            
            int n = q.size(); // n element in current level
            
            int prev;
            //if it's even level
            if(even_level){
                prev = INT_MIN; // bcoz incresing order
            }
            else{
                //if odd
                prev = INT_MAX;
            }
            
            while(n--){
                curr = q.front();
                q.pop();
                
                //if level is even so node val will be odd
                
                if(even_level && (curr->val % 2 == 0 || curr->val <= prev ) ){
                    return false;// even level me odd val hona chahihe
                }
                
                //if odd level
                if(!even_level && (curr->val % 2 != 0 || curr->val >= prev ) ){
                    return false;// even level me odd val hona chahihe
                }
                
                prev = curr->val;
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }
            //level change now it's odd
            even_level = !even_level;
            
        }
        return true;
    }
};