// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n= nums.size();
//         long ans = 0;
        
//         for(int i=0;i<n;i++){
//             for(int j=i+1; j<n ; j++){
//                 for(int k = j+1 ; k<n ; k++){
//                    long val = (long)(nums[i]-nums[j]) * (long) nums[k];
                    
//                     // if(ans < 0)
//                     //     return 0;
//                     if(val > ans)
//                         ans = val;
//                 }
//             }
//         }
            
//         return ans;
//     }
// };

// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n= nums.size();
//         long ans = 0;
//         int maxi = nums[0];
        
        
//             for(int j=1; j<n ; j++){
//                 maxi = max(maxi , nums[j-1]); //may be we will find more greter val
//                 for(int k = j+1 ; k<n ; k++){
//                    long val = (long)(maxi - nums[j]) * (long) nums[k];
                    
//                     // if(ans < 0)
//                     //     return 0;
//                     if(val > ans)
//                         ans = val;
//                 }
//             }
        
            
//         return ans;
//     }
// };

// make diff= maxi - nums[j] 
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        long ans = 0;
        int maxi = max(nums[0] , nums[1]); //maxi on left of j
        int max_diff = nums[0] - nums[1];// i - j
        
        

        for(int k = 2 ; k<n ; k++){
           long val = (long)(max_diff) * (long) nums[k];
            
            // if(ans < 0)
            //     return 0;
            if(val > ans)
                ans = val;
            //update maxdiff and maxi for next iteration
            max_diff = max(max_diff , maxi-nums[k]);
            maxi = max(maxi , nums[k]);
        }
   
            
        return ans;
    }
};

