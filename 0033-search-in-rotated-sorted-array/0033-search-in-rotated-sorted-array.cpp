// BRUTE FORCE

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i =0 ; i<n ; i++){
             if(nums[i] == target)
                 return i;
        }
        return -1;
    }
};


// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int low = 0 , high = n-1;
//         // int mid = (low+mid)/2;
//         int mid = low + (high - low)/2;
        
//         while(low<high){
//             // int mid = (low+mid)/2;
//             if(nums[mid] == target){
//                    return mid;
//             }
            
//             else if(nums[mid] > target){
//                 mid++;
//             }
            
//             else if(nums[mid] < target){
//                 mid--;
//             }
            
//             else{
//                 return -1;
//             }
//         }
//         return mid;
        
//     }
// };


// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int left = 0, right = nums.size()-1;
        
//         while (left <= right){
//             int mid = left + (right - left)/2;
            
//             if (nums[mid] == target){
//                 return mid;
//             }else if (nums[mid] > nums[right]){
                
//                 if (target >= nums[left] && target < nums[mid]){
//                     right = mid-1;
//                 }else {
//                     left = mid+1;
//                 }
//             }else {
//                 // right part is sorted 
                
//                 // range [nums[mid]......nums[high]]
//                 if (target > nums[mid] && target <= nums[right]){
//                     left = mid+1;
//                 }else {
//                     right = mid-1;
//                 }
//             }
//         }
//         return -1;
//     }
// };