// [1,2,3] permutation ->
//     1 2 3
//     1 3 2
//     2 1 3
//     2 3 1
//     3 1 2 
//     3 2 1
// next permutation of [1 2 3] = 1 3 2
// next permutation of [3 2 1] = 1 2 3 assending order 

// BRUTE FORCE
// 1ST find all the permutation in sorted order
//  then do liner search to find the given arr permu
// then next index permu is my answer o(n*N)

// direct use stl library 
// next_permutation(nums.begin() , nums.end());
//          return nums;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size(), i , j;
         
         for(i = n-2 ; i>=0 ; i--){
             if(nums[i] < nums[i+1]){
                 break;
             }
         }
         if(i<0){
             reverse(nums.begin() , nums.end());
         }
         else{
             for(j=n-1; j>i; j--){
                 if(nums[j] > nums[i]){
                     break;
                 }
             }
             swap(nums[i] , nums[j]);
             reverse(nums.begin() + i+1, nums.end());
         }
        
    }
};