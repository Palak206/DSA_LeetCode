class Solution {
public:
    int findMin(vector<int>& nums) {
        // int min_num;
        // // sort(nums.begin() , nums.end());
        return *min_element(nums.begin() , nums.end());
        // return min_num;
        
        
//         int n = nums.size();
//         int low = 0 , high = n-1;
        
//         while(low < high){
//             // int mid = (low+high)/2;
//             int mid = (low + high)/2;
//           // int mid = low + (high - low)/2;
            
//             if(nums[mid] > nums[high]){
//                 low = mid+1;
//             }
            
//             else{
//                 high = mid;
//                }
//         }
//         return nums[low];
        
    }
};