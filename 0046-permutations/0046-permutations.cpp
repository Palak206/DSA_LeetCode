// class Solution {
// public:
//     vector<vector<int>> perm(vector<int>& nums){
        
//         if(nums.size() == 0){
//             return {{}};
//         }
        
    
//         vector<vector<int>> ans;
//         // each number 1 , 2 , 3
//         for(int i= 0; i<nums.size(); i++){
            
//             vector<int> nums2;
            
//             for(int j= 0; j<nums.size(); j++){
//                 if(i != j){
//                     nums2.push_back(nums[j]);//except ith element
//                 }
//             }
//             vector<vector<int>> v=perm(nums2); // 1,perm(2,3)
//             for(auto a:v){
//                 a.push_back(nums[i]);
//                 ans.push_back(a);
//             }
            
//         }
//         return ans;
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         return perm(nums);
//     }
// };


class Solution {
public:
    vector<vector<int>> ans;
    void perm(vector<int>& nums , int i ){// pass reference it'll create copy of no.
        if(i == nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int j= i; j<nums.size();j++){
            swap(nums[i],nums[j]);
            perm(nums , i+1);
            swap(nums[i] ,nums[j]);//undo the chage
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      
        perm(nums , 0);
        return ans;
    }
};