// class Solution {
// public:
//     int splitArray(vector<int>& nums, int k) {
//         sort(nums.begin() , nums.end());
//         // vector<int>ans;
//         int n =nums.size();
//        int l_sum = 0 ;
//        int r_sum = 0;
//         int sum = 0;
//         int i , j ;
        
//         for(i = 0 ; i<k ; i++){
//              l_sum += nums[i];
//             // if(n == k && nums[i] < nums[i+1]){
//             //     // if(nums[i] < nums[i+1]){
//             //         return nums[i+1];
//             //     }
//         }
//         for(i = 0 ; i<n ; i++){
//             sum += nums[i];
//         }
        
        
//         for(j = n-1 ; j>k ; j--){
//              r_sum += nums[j];
//         }
//         if(l_sum < r_sum){
//              r_sum;
//         }
//         if(k == 1){
//                     // sum += nums[i];
//              return sum;
//           }
        
//          return r_sum;   
        
        
        
//     }
// };



class Solution{
    public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end()); // 8
        int high = accumulate(nums.begin(),nums.end(),0); // 23
        int ans = low;
        while(low<=high)
        {
            int mid = (low+high)/2; // limit
            int n =no_of_subarrays_with_max_sum_as_mid(nums,mid);
            if(n>k)
              low = mid+1;
            else
            {
                ans = mid; //minimize ans
                high = mid-1;         
                
            }
          
                
        }
        
        return ans;
        
        
    }
    
     int no_of_subarrays_with_max_sum_as_mid(vector<int>&nums, int mid){
       int sum =0;
       int count = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]>mid)
            {
                sum = nums[i];
                count++;
            }
            else
                sum+=nums[i];
        }
      
      return count;
     
     }
};