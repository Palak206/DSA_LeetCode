// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         return *min_element(nums.begin() , nums.end());
//     }
// };

class Solution{
    public:
    int findMin(vector<int>& nums){
        int n = nums.size();
        int mini = INT_MAX;
        
        for(int i=0; i<n; i++){
            mini = min(mini,nums[i]);
        }
        return mini;
    }
};

// class Solution {
// public:
//     int findMin(vector<int>& nums){
        
//         int n = nums.size();
//         int low = 0 , high = n-1;
        
//         while(low < high){
//             int mid = (low + high)/2;
         
//             if(nums[mid] > nums[high]){
//                 low = mid+1;
//             }
            
//             else{
//                 high = mid;
//                }
//         }
//         return nums[low];
        
//     }
// };