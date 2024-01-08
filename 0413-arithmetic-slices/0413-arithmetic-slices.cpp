// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size();
        
//         // if size of arr is < 3 then false at least 3elements should be there
//         if(n<3)
//             return false;
        
//         int count =0; 
//         int diff;
        
//         //2 consecutive
//         for(int i=0; i<n-2; i++){
//             int diff = nums[i+1]-nums[i];
            
//             //for contigious
//             for(int j=i+2; j<n; j++){
//                 if(nums[j]-nums[j-1] == diff)
//                     count++;
//                 else
//                     break;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        // if size of arr is < 3 then false at least 3elements should be there
        if(n<3)
            return false;
        
        int count = 0 ,ind=0; 
        int prev_diff = nums[1]-nums[0];
        
        //2 consecutive
        for(int i=2; i<n; i++){
            int diff = nums[i]-nums[i-1];
            if(diff == prev_diff){
                ind++; 
            }
           else{
               prev_diff = diff;
               ind = 0;
           }
           count += ind;
        }
        return count;
    }
};