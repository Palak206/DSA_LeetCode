// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int n = nums.size();
        
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n-1; j++){
//                 for(int k = j+1; k<n-2; k++){
//                     if(i<j || j<k ||i<k){
//                         if(nums[i] < nums[j] || nums[j] < nums[k] || nums[i]<nums[k])
//                           return true;
//                     }
                    
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        
        for(int i=0; i<n; i++){
            int num3 = nums[i];
            
            //ask num1 <= bcoz [1,1,1]
            if(num3 <= num1){
                num1 = num3;
            }
            
            else if(num3 <= num2){
                num2 = num3;
            }
            
            else{
                //n1<n2 
                return true;
            }
        }
        return false;
    }
};