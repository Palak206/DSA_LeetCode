// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         return *min_element(nums.begin() , nums.end());
//     }
// };

// class Solution{
//     public:
//     int findMin(vector<int>& nums){
//         int n = nums.size();
//         int mini = INT_MAX;
        
//         for(int i=0; i<n; i++){
//             mini = min(mini,nums[i]);
//         }
//         return mini;
//     }
// };

// If arr[low] <= arr[mid]: In this case, we identified that the left half is sorted.
// If arr[mid] <= arr[high]: In this case, we identified that the right half is sorted.

class Solution{
    public:
    int findMin(vector<int>& nums){
        int n = nums.size();
        int l = 0, h = n-1;
        int ans = INT_MAX;
        
        while(l<=h){
            int mid = l+(h-l)/2;
            
            //if left half is sorted
            if(nums[l] <= nums[mid]){
                ans = min(ans , nums[l]);
                l = mid+1;
            }
            else{
                //if right half is sorted
                ans = min(ans,nums[mid]);
                h=mid-1;
            }
        }
        return ans;
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