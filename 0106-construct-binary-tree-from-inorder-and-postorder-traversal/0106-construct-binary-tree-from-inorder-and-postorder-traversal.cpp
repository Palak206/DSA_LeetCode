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
// we move with the postorder 
// unordermap to store the index of the current root node in inorder to get rid of left & right
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& mp, int& rootIdx, int left, int right) {
        if(left > right) return NULL;
        
        int pivot = mp[postorder[rootIdx]];
        TreeNode* node = new TreeNode(postorder[rootIdx]);
        rootIdx--;

        node->right = buildTreeHelper(inorder, postorder, mp, rootIdx, pivot+1, right);
        node->left = buildTreeHelper(inorder, postorder, mp, rootIdx, left, pivot-1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = postorder.size()-1;
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, mp, rootIdx, 0, inorder.size()-1);
    }
};