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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* curr = root;
        q.push(curr);
        vector<double> v;
        
        while(!q.empty()){
            double n = q.size();
            double sum = 0;
            double avg;
            
            for(int i=0; i<n; i++){
               curr = q.front();
               q.pop();
                
               sum += curr->val;
                
               if(curr->left)
                q.push(curr->left);
                
               if(curr->right)
                q.push(curr->right);
            
            }
            avg = sum/n;
            v.push_back(avg);
            
        }
        return v;
    }
};