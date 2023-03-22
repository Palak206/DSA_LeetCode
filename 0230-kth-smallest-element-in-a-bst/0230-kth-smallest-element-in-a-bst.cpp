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
//inorder traversal so alll node get sorted
// v = [1 2 3 4]
// then v(k-1)th index = 1-1 = v[0] = 1

// T.C & S.C = O(N)
// class Solution {
// public:
//     vector<int>v;
//     void inorder(TreeNode* root){
//         if(root == NULL){
//             return ;
//         }
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
        
        
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         if(root == NULL)
//             return NULL;
//         inorder(root);
//         return v[k-1];
        
        
        
//     }
// };

// T.C = O(LOGN) S.C = O(N)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector <int> ans;
        solve(root, ans);
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }

    void solve(TreeNode* root, vector <int>& ans) {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        solve(root->left, ans);
        solve(root->right, ans);    
    }
};