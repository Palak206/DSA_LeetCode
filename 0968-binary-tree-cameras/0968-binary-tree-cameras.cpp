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
// class Solution {
//     int cam;
//     set<TreeNode*>covered;
// public:
//     int minCameraCover(TreeNode* root) {
//         // if(root == NULL) return 0;
//         // cam = 0;
//         // covered = new hashset<>();
//         // covered.add(NULL);
//         // //whenwe go to the deepest node it child node should not be covered
//         // // it would not contain child node for the leaf node that is null
//         // dfs(root , NULL);//parent of the root is null bcoz it does not have any parent
//         // return cam;
        
//         if(root == NULL) return 0; // no node no camera required;
       
//        //I have inserted NULL to the covered because we don't want
//        //camera to be installed at the leaf nodes
//        covered.insert(NULL);
//        cam = 0;
       
//        // Now we will pass root and a NULL pointer as a argument
//        // NULL pointer points to the parent node of the current node
//        // in our case as root as no parent we will pass NULL
       
//        dfs(root,NULL);
//        return cam;
//     }
//     void dfs(TreeNode* node , TreeNode* parent){
//         if(node != NULL){
//             dfs(node->left , node);
//             dfs(node->right , node);
//             //we are at the depth of the tree now we want to check weather
//            //we need camera at the node
//             // check  if i need to add camera at node
//              // for that parent is null & node is uncovered
//               //OR
//             //IF ANY OF ITS LEFT OR RIGHT child are not  UNCOVERED so then add camera
            
//             if(parent == NULL && !covered.contains(node)
//               || !covered.contains(node->left) || !covered.contains(node->right) ){
//                 cam++;
//                 covered.add(node);
//                 covered.add(parent);
//                 covered.add(node->left);
//                 covered.add(node->right);
//             }
//         }
//     }
// };

// T.C & S.C = O(N)
// class Solution {
// public:
//    int cam;
//    set<TreeNode*>covered;
   
//    void dfs(TreeNode*node, TreeNode*parent){
//        if(node!=NULL){  
//            dfs(node->left, node);
//            dfs(node->right, node);
           
//            //we are at the depth of the tree now we want to check weather
//            //we need camera at the node
//            //check if parent is null or uncovered
//            // OR
//            // any of its child left or right is uncovered
//            if(
//                (parent == NULL && covered.find(node) == covered.end()) ||
//                (covered.find(node->left) == covered.end()) ||
//                (covered.find(node->right) == covered.end())
//            ){
//                cam++;
//                covered.insert(node);
//                covered.insert(parent);
//                covered.insert(node->left);
//                covered.insert(node->right);
//            }
//        }
//    }
   
//    int minCameraCover(TreeNode* root) {
//        if(root == NULL) return 0; // no node no camera required;
       
//        //I have inserted NULL to the covered because we don't want
//        //camera to be installed at the leaf nodes
//        covered.insert(NULL);
//        cam = 0;
       
//        // Now we will pass root and a NULL pointer as a argument
//        // NULL pointer points to the parent node of the current node
//        // in our case as root as no parent we will pass NULL
       
//        dfs(root,NULL);
//        return cam;
//    }
// };

// T.C = O(N) S.C = O(1)
class Solution{
    int cam = 0;
    public:
          int minCameraCover(TreeNode* root) {
              
             int ans = dfs(root);
              //  if 0 (uncovered) then cam+1
              //if (1 ,2) node covered then return the no. of camera that have added in the tree
              return ans == 0 ? cam+1 : cam;
          }
    
    int dfs(TreeNode* node){
        // 0 for uncovered node
        //1 for node covered with camera
        // 2 for node with camera
        if(node == NULL) return 1;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        if(left == 0 || right == 0){
            cam++;
            return 2; //camera
        }
        else if(left == 2 || right == 2)
            return 1;//covered
        else
            return 0; //uncovered
    }
};